#ifndef _OBJECTS_H_
#define _OBJECTS_H_


class IntegerObject
{

public:

    explicit IntegerObject(int value = 0) : m_value(value) {}

    int value() const { return m_value; }


private:

    int m_value;
};


class PairObject
{

public:

    PairObject(int first = 0, int second = 0) : m_first(first), m_second(second) {}

    int first() const { return m_first; }

    int second() const { return m_second; }


private:

    int m_first;

    int m_second;
};


enum class ObjectType : int
{
    Integer = 0,
    Pair = 1
};


struct SerializedObject
{
    explicit SerializedObject(const IntegerObject &object) : type(ObjectType::Integer), first(object.value()), second(0) {}

    explicit SerializedObject(const PairObject &object) : type(ObjectType::Pair), first(object.first()), second(object.second()) {}


    ObjectType type;

    int first;

    int second;
};


#endif
