#include "serializer.h"

#include <fstream>
#include <iostream>


bool Serializer::serialize(const char *path) const
{
    std::ofstream out(path, std::ios::binary | std::ios::trunc);

    if (!out.write(reinterpret_cast<const char *>(&m_value), sizeof(m_value))) return false;
    out.close();


    return static_cast<bool>(out);
}

bool Serializer::deserialize(const char *path, Serializer &result)
{
    std::ifstream in(path, std::ios::binary);
    int value;

    if (!in || !in.read(reinterpret_cast<char *>(&value), sizeof(value))) return false;
    result = Serializer(value);


    return true;
}

void Serializer::print() const
{
    std::cout << "value = " << m_value << '\n';
}
