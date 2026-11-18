#ifndef _SERIALIZABLE_OBJECT_H_
#define _SERIALIZABLE_OBJECT_H_

#include <iosfwd>


class SerializableObject
{

public:

    explicit SerializableObject(int value = 0) : m_value(value) {}

    bool serialize(std::ostream &out) const;

    bool deserialize(std::istream &in);

    void print() const;


private:

    int m_value;
};


#endif
