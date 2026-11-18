#include "serializer.h"

#include <fstream>


bool Serializer::serialize(const char *path, const std::vector<SerializedObject> &objects) const
{
    std::ofstream out(path, std::ios::binary | std::ios::trunc);
    if (!out) return false;

    for (auto &object : objects)
    {
        int type = static_cast<int>(object.type);
        if (!out.write(reinterpret_cast<const char *>(&type), sizeof(type))) return false;

        if (ObjectType::Integer == object.type)
        {
            if (!out.write(reinterpret_cast<const char *>(&object.first), sizeof(object.first))) return false;
        }
        else if (ObjectType::Pair == object.type)
        {
            if (!out.write(reinterpret_cast<const char *>(&object.first), sizeof(object.first)) || !out.write(reinterpret_cast<const char *>(&object.second), sizeof(object.second))) return false;
        }
        else
        {
            return false;
        }
    }

    out.close();


    return static_cast<bool>(out);
}

bool Serializer::deserialize(const char *path, std::vector<SerializedObject> &objects) const
{
    std::ifstream in(path, std::ios::binary);
    if (!in) return false;

    std::vector<SerializedObject> restored;
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

        int first, second = 0;
        if (static_cast<int>(ObjectType::Integer) == type)
        {
            if (!in.read(reinterpret_cast<char *>(&first), sizeof(first))) return false;

            restored.emplace_back(IntegerObject(first));
        }
        else if (static_cast<int>(ObjectType::Pair) == type)
        {
            if (!in.read(reinterpret_cast<char *>(&first), sizeof(first)) || !in.read(reinterpret_cast<char *>(&second), sizeof(second))) return false;

            restored.emplace_back(PairObject(first, second));
        }
        else
        {
            return false;
        }
    }
}
