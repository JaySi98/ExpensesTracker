#include <data/transaction_type.hpp>
#include <data/monthly_budget.hpp>
#include <data/options_parser.hpp>

void add_transaction(const po::variables_map& parsed_variables);
void print_monthly_budget(const po::variables_map& parsed_variables);
void print_help();
void print_transaction_categories();


int main(int argc, char** argv) 
{
    options_parser parser(argc, argv);
    auto variables = parser.get_variables();

    if(variables.count("add"))
    {
        add_transaction(variables);
    }
    else if(variables.count("month"))
    {
        print_monthly_budget(variables);
    }
    else if(variables.count("help"))
    {
        print_help();
    }

    else if(variables.count("types"))
    {
        print_transaction_categories();
    }
}

void add_transaction(const po::variables_map& parsed_variables)
{
    date d{};
    std::string note{};
    float value{0};
    transaction_category category{transaction_category::unknown};

    if(parsed_variables.count("date"))
    {
        std::string date_str = parsed_variables["date"].as<std::string>(); 
        d = from_simple_string(date_str);
    }

    if(parsed_variables.count("note"))
    {
        note = parsed_variables["note"].as<std::string>();
    }

    if(parsed_variables.count("value"))
    {
        value = parsed_variables["value"].as<float>();
    }

    if(parsed_variables.count("cat"))
    {
        std::string s_type = parsed_variables["cat"].as<std::string>();
        
        auto find_type = std::find_if(std::begin(str_tran_cat), std::end(str_tran_cat), [&](const std::pair<transaction_category, std::string>& pair)
        {
            return pair.second.compare(s_type) == 0; 
        });

        if(find_type != std::end(str_tran_cat))
        {
            category = find_type->first;
        }
    }

    transaction trans{0, d, category, note, value};
    std::cout << trans << std::endl;
}

void print_monthly_budget(const po::variables_map& parsed_variables)
{
    std::cout << "monthly budget hehe" << std::endl;
}

void print_help()
{
    std::cout << "help hehe" << std::endl;
    print_transaction_categories();
}

void print_transaction_categories()
{
    std::cout << "types hehe" << std::endl;
}