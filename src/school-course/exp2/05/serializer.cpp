#include "serializer.h"

#include <fstream>
#include <utility>


bool Serializer::registerType(int type, const ObjectFactory &factory)
{
    if (!factory || m_factories.end() != m_factories.find(type)) return false;

    m_factories[type] = factory;
    return true;
}

bool Serializer::serialize(const char *path, const std::vector<std::unique_ptr<IsSerializable>> &objects) const
{
    std::ofstream out(path, std::ios::binary | std::ios::trunc);
    if (!out) return false;

    for (auto &object : objects)
    {
        if (!object) return false;

        int type = object->type();
        if (m_factories.end() == m_factories.find(type)) return false;

        if (!out.write(reinterpret_cast<const char *>(&type), sizeof(type)) || !object->serialize(out)) return false;
    }

    out.close();
    return static_cast<bool>(out);
}

bool Serializer::deserialize(const char *path, std::vector<std::unique_ptr<IsSerializable>> &objects) const
{
    std::ifstream in(path, std::ios::binary);
    if (!in) return false;

    std::vector<std::unique_ptr<IsSerializable>> restored;
    for (;;)
    {
        int type;
        if (!in.read(reinterpret_cast<char *>(&type), sizeof(type)))
        {
            if (in.eof() && 0 == in.gcount())
            {
                objects.swap(restored);
                return true;
            }
            return false;
        }

        auto factory = m_factories.find(type);
        if (m_factories.end() == factory) return false;

        std::unique_ptr<IsSerializable> object = factory->second();
        if (!object || object->type() != type || !object->deserialize(in)) return false;

        restored.push_back(std::move(object));
    }
}
