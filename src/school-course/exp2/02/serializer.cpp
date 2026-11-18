#include "serializer.h"

#include <fstream>


bool Serializer::serialize(const char *path, const std::vector<SerializableObject> &objects) const
{
    std::ofstream out(path, std::ios::binary | std::ios::trunc);
    if (!out) return false;

    for (auto &object : objects)
    {
        if (!object.serialize(out)) return false;
    }

    out.close();


    return static_cast<bool>(out);
}

bool Serializer::deserialize(const char *path, std::vector<SerializableObject> &objects) const
{
    std::ifstream in(path, std::ios::binary);
    if (!in) return false;

    std::vector<SerializableObject> restored;
    for (;;)
    {
        SerializableObject object;
        if (object.deserialize(in))
        {
            restored.push_back(object);
        }
        else if (in.eof() && 0 == in.gcount())
        {
            objects.swap(restored);
            return true;
        }
        else
        {
            return false;
        }
    }
}
