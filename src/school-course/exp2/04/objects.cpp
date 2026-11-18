#include "objects.h"

#include <iostream>
#include <istream>
#include <ostream>


bool IntegerObject::serialize(std::ostream &out) const
{
    return static_cast<bool>(out.write(reinterpret_cast<const char *>(&m_value), sizeof(m_value)));
}

bool IntegerObject::deserialize(std::istream &in)
{
    return static_cast<bool>(in.read(reinterpret_cast<char *>(&m_value), sizeof(m_value)));
}

void IntegerObject::print() const
{
    std::cout << "IntegerObject: " << m_value << '\n';
}

bool PairObject::serialize(std::ostream &out) const
{
    return static_cast<bool>(out.write(reinterpret_cast<const char *>(&m_first), sizeof(m_first)) && out.write(reinterpret_cast<const char *>(&m_second), sizeof(m_second)));
}

bool PairObject::deserialize(std::istream &in)
{
    return static_cast<bool>(in.read(reinterpret_cast<char *>(&m_first), sizeof(m_first)) && in.read(reinterpret_cast<char *>(&m_second), sizeof(m_second)));
}

void PairObject::print() const
{
    std::cout << "PairObject: " << m_first << ", " << m_second << '\n';
}

bool TripleObject::serialize(std::ostream &out) const
{
    return static_cast<bool>(out.write(reinterpret_cast<const char *>(&m_first), sizeof(m_first)) && out.write(reinterpret_cast<const char *>(&m_second), sizeof(m_second)) && out.write(reinterpret_cast<const char *>(&m_third), sizeof(m_third)));
}

bool TripleObject::deserialize(std::istream &in)
{
    return static_cast<bool>(in.read(reinterpret_cast<char *>(&m_first), sizeof(m_first)) && in.read(reinterpret_cast<char *>(&m_second), sizeof(m_second)) && in.read(reinterpret_cast<char *>(&m_third), sizeof(m_third)));
}

void TripleObject::print() const
{
    std::cout << "TripleObject: " << m_first << ", " << m_second << ", " << m_third << '\n';
}
