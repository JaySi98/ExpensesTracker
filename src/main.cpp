#include <iostream>
#include <transaction.hpp>

int main(int argc, char** argv) 
{
    std::cout << "Hello World!" << std::endl;

    date d1{2020,12,5};
    std::cout << d1 << std::endl;

    date d2 = day_clock::universal_day();
    std::cout << d2 << std::endl;

    transaction trans;
    std::cout << trans << std::endl;

    return EXIT_SUCCESS;
}