#ifndef _SERIALIZER_H_
#define _SERIALIZER_H_

#include "serializableobject.h"

#include <vector>


class Serializer
{

public:

    bool serialize(const char *path, const std::vector<SerializableObject> &objects) const;

    bool deserialize(const char *path, std::vector<SerializableObject> &objects) const;
};


#endif
