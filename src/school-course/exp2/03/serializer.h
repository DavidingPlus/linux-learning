#ifndef _SERIALIZER_H_
#define _SERIALIZER_H_

#include "objects.h"

#include <vector>


class Serializer
{

public:

    bool serialize(const char *path, const std::vector<SerializedObject> &objects) const;

    bool deserialize(const char *path, std::vector<SerializedObject> &objects) const;
};


#endif
