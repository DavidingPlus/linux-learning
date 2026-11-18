#include "serializableobject.h"

#include <iostream>
#include <istream>
#include <ostream>


bool SerializableObject::serialize(std::ostream &out) const
{
    return static_cast<bool>(out.write(reinterpret_cast<const char *>(&m_value), sizeof(m_value)));
}

bool SerializableObject::deserialize(std::istream &in)
{
    int value;
    if (!in.read(reinterpret_cast<char *>(&value), sizeof(value))) return false;

    m_value = value;
    return true;
}

void SerializableObject::print() const
{
    std::cout << "value = " << m_value << '\n';
}
