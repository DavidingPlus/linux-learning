#include "objects.h"
#include "serializer.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>


int main()
{
    std::ifstream config("school-course-exp2-05-config.txt");
    std::string path;
    if (!std::getline(config, path))
    {
        std::cerr << "failed to read school-course-exp2-05-config.txt\n";
        return EXIT_FAILURE;
    }

    std::string::size_type begin = path.find_first_not_of(" \t\r");
    if (std::string::npos == begin)
    {
        std::cerr << "school-course-exp2-05-config.txt has an empty path\n";
        return EXIT_FAILURE;
    }
    path = path.substr(begin, path.find_last_not_of(" \t\r") - begin + 1);

    Serializer serializer;
    if (!serializer.registerType(IntegerObjectType, []()
                                 { return std::unique_ptr<IsSerializable>(new IntegerObject); }) ||
        !serializer.registerType(PairObjectType, []()
                                 { return std::unique_ptr<IsSerializable>(new PairObject); }) ||
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

    if (!serializer.serialize(path.c_str(), original))
    {
        std::cerr << "failed to serialize " << path << '\n';
        return EXIT_FAILURE;
    }

    std::vector<std::unique_ptr<IsSerializable>> restored;
    if (!serializer.deserialize(path.c_str(), restored))
    {
        std::cerr << "failed to deserialize " << path << '\n';
        return EXIT_FAILURE;
    }

    for (auto &object : restored) object->print();
}
