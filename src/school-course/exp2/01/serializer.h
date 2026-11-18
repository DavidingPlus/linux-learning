#ifndef _SERIALIZER_H_
#define _SERIALIZER_H_

class Serializer
{

public:

    explicit Serializer(int value = 0) : m_value(value) {}

    bool serialize(const char *path) const;

    static bool deserialize(const char *path, Serializer &result);

    void print() const;


private:

    int m_value;
};


#endif
