#include <data/transaction_type.hpp>
#include <data/monthly_budget.hpp>
#include <functional/options_parser.hpp>
#include <functional/options_controller.hpp>

void add_transaction(const po::variables_map& parsed_variables);
void print_monthly_budget(const po::variables_map& parsed_variables);
void print_help();
void print_transaction_categories();


int main(int argc, char** argv) 
{
    functional::options_parser parser(argc, argv);
    functional::options_controller controller(parser.get_variables());
    controller.execute_option_command();
}