#include "serializer.h"

#include <iostream>


int main()
{
    const char *path = "school-course-exp2-01.data";

    Serializer original(100);
    if (!original.serialize(path))
    {
        std::cerr << "failed to serialize " << path << '\n';
        return EXIT_FAILURE;
    }

    Serializer restored;
    if (!Serializer::deserialize(path, restored))
    {
        std::cerr << "failed to deserialize " << path << '\n';
        return EXIT_FAILURE;
    }

    restored.print();
}
