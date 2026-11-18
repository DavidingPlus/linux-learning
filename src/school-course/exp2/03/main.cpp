#include "serializer.h"

#include <iostream>
#include <vector>


int main()
{
    const char *path = "school-course-exp2-03.data";

    std::vector<SerializedObject> original{SerializedObject(IntegerObject(100)), SerializedObject(PairObject(200, 201)), SerializedObject(PairObject(300, 301)), SerializedObject(IntegerObject(400))};

    Serializer serializer;
    if (!serializer.serialize(path, original))
    {
        std::cerr << "failed to serialize " << path << '\n';
        return EXIT_FAILURE;
    }

    std::vector<SerializedObject> restored;
    if (!serializer.deserialize(path, restored))
    {
        std::cerr << "failed to deserialize " << path << '\n';
        return EXIT_FAILURE;
    }

    for (auto &object : restored)
    {
        if (ObjectType::Integer == object.type)
        {
            IntegerObject restoredObject(object.first);

            std::cout << "IntegerObject: " << restoredObject.value() << '\n';
        }
        else
        {
            PairObject restoredObject(object.first, object.second);

            std::cout << "PairObject: " << restoredObject.first() << ", " << restoredObject.second() << '\n';
        }
    }
}
