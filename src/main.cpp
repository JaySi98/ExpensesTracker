#include <iostream>
#include <transaction.hpp>
#include "transaction_type.hpp"
#include <options_parser.hpp>

int main(int argc, char** argv) 
{
    date d1{2020,12,5};
    std::cout << d1.month() << std::endl;

    transaction trans1{d1,transaction_type::house_maintenance, "some note", 120  };
    std::cout << trans1 << std::endl;

    //
    options_parser parser(argc, argv);

    return EXIT_SUCCESS;
}