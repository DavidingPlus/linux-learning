#ifndef _OBJECTS_H_
#define _OBJECTS_H_

#include "isserializable.h"


enum ObjectType
{
    IntegerObjectType = 0,
    PairObjectType = 1,
    TripleObjectType = 2
};


class IntegerObject : public IsSerializable
{

public:

    explicit IntegerObject(int value = 0) : m_value(value) {}

    int type() const override { return IntegerObjectType; }

    bool serialize(std::ostream &out) const override;

    bool deserialize(std::istream &in) override;

    void print() const override;


private:

    int m_value;
};

class PairObject : public IsSerializable
{

public:

    PairObject(int first = 0, int second = 0) : m_first(first), m_second(second) {}

    int type() const override { return PairObjectType; }

    bool serialize(std::ostream &out) const override;

    bool deserialize(std::istream &in) override;

    void print() const override;


private:

    int m_first;

    int m_second;
};

class TripleObject : public IsSerializable
{

public:

    TripleObject(int first = 0, int second = 0, int third = 0) : m_first(first), m_second(second), m_third(third) {}

    int type() const override { return TripleObjectType; }

    bool serialize(std::ostream &out) const override;

    bool deserialize(std::istream &in) override;

    void print() const override;


private:

    int m_first;

    int m_second;

    int m_third;
};

#endif
