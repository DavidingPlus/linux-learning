#include "objects.h"
#include "serializer.h"

#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>


int main()
{
    const char *path = "school-course-exp2-04.data";

    Serializer serializer;
    if (!serializer.registerType(IntegerObjectType, []()
                                 { return std::unique_ptr<IsSerializable>(new IntegerObject); }) //
        ||
        !serializer.registerType(PairObjectType, []()
                                 { return std::unique_ptr<IsSerializable>(new PairObject); }) //
        ||
        !serializer.registerType(TripleObjectType, []()
                                 { return std::unique_ptr<IsSerializable>(new TripleObject); }))
    {
        std::cerr << "failed to register object type\n";
        return EXIT_FAILURE;
    }

    std::vector<std::unique_ptr<IsSerializable>> original;
    original.emplace_back(new IntegerObject(100));
    original.emplace_back(new PairObject(200, 201));
    original.emplace_back(new TripleObject(300, 301, 302));
    original.emplace_back(new IntegerObject(400));

    if (!serializer.serialize(path, original))
    {
        std::cerr << "failed to serialize " << path << '\n';
        return EXIT_FAILURE;
    }

    std::vector<std::unique_ptr<IsSerializable>> restored;
    if (!serializer.deserialize(path, restored))
    {
        std::cerr << "failed to deserialize " << path << '\n';
        return EXIT_FAILURE;
    }

    for (auto &object : restored) object->print();
}
