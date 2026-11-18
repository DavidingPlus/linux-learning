#ifndef _ISSERIALIZABLE_H_
#define _ISSERIALIZABLE_H_

#include <iosfwd>


class IsSerializable
{

public:

    virtual ~IsSerializable() {}

    virtual int type() const = 0;

    virtual bool serialize(std::ostream &out) const = 0;

    virtual bool deserialize(std::istream &in) = 0;

    virtual void print() const = 0;
};


#endif
