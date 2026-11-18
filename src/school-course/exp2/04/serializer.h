#ifndef _SERIALIZER_H_
#define _SERIALIZER_H_

#include "isserializable.h"

#include <functional>
#include <map>
#include <memory>
#include <vector>


class Serializer
{

public:

    using ObjectFactory = std::function<std::unique_ptr<IsSerializable>()>;

    bool registerType(int type, const ObjectFactory &factory);

    bool serialize(const char *path, const std::vector<std::unique_ptr<IsSerializable>> &objects) const;

    bool deserialize(const char *path, std::vector<std::unique_ptr<IsSerializable>> &objects) const;


private:

    std::map<int, ObjectFactory> m_factories;
};


#endif
