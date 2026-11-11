#include <iostream>
#include <string>


int main(int argc, char *argv[])
{
    if (2 != argc || ("clean" != std::string(argv[1]) && "leak" != std::string(argv[1]) && "invalid" != std::string(argv[1])))
    {
        std::cerr << "Usage: " << argv[0] << " clean|leak|invalid\n";
        return EXIT_FAILURE;
    }

    std::string mode = argv[1];
    int *values = new int[5]{1, 2, 3, 4, 5};

    if ("invalid" == mode)
    {
        std::cout << "value: " << values[5] << '\n';
    }
    else
    {
        std::cout << "value: " << values[0] << '\n';
    }
    if ("leak" != mode)
    {
        delete[] values;
    }
}
