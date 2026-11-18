#include "serializer.h"

#include <iostream>
#include <vector>


int main()
{
    const char *path = "school-course-exp2-02.data";

    std::vector<SerializableObject> original{SerializableObject(100), SerializableObject(200), SerializableObject(300)};

    Serializer serializer;
    if (!serializer.serialize(path, original))
    {
        std::cerr << "failed to serialize " << path << '\n';
        return EXIT_FAILURE;
    }

    std::vector<SerializableObject> restored;
    if (!serializer.deserialize(path, restored))
    {
        std::cerr << "failed to deserialize " << path << '\n';
        return EXIT_FAILURE;
    }

    for (auto &object : restored) object.print();
}
