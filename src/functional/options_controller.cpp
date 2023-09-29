#include <functional/options_controller.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/date_clock_device.hpp>

using namespace boost::gregorian;

namespace functional 
{
    options_controller::options_controller(const po::variables_map& variables)
        : m_variables(&variables)
    { }

    void options_controller::execute_option_command()
    {
        if(option_set(options::add))
        {
            add_transaction();
        }
        else if(option_set(options::month))
        {
            print_monthly_budget();
        }
        else if(option_set(options::help))
        {
            print_help();
        }
        else if(option_set(options::types))
        {
            print_categories();
        }
    }
    
    bool options_controller::option_set(options option)
    {
        return m_variables->count(str_options[option].c_str());
    }

    template<typename T>
    T options_controller::get_option_value(options option)
    {
        // std::string str_option{str_options[option].c_str()};
        // return m_variables[str_option].as<T>();
    }

    void options_controller::add_transaction()
    {
        date d{day_clock::universal_day()};
        std::string note{""};
        float value{0};
        transaction_category category{transaction_category::unknown};

        if(option_set(options::date))
        {
            // std::string date_str = parsed_variables["date"].as<std::string>(); 
            // d = from_simple_string(date_str);
        }

        if(option_set(options::note))
        {
            // note = parsed_variables["note"].as<std::string>();
        }

        if(option_set(options::value))
        {
            // value = parsed_variables["value"].as<float>();
        }

        if(option_set(options::category))
        {
            // std::string s_type = parsed_variables["cat"].as<std::string>();
            
            // auto find_type = std::find_if(std::begin(str_tran_cat), std::end(str_tran_cat), [&](const std::pair<transaction_category, std::string>& pair)
            // {
            //     return pair.second.compare(s_type) == 0; 
            // });

            // if(find_type != std::end(str_tran_cat))
            // {
            //     category = find_type->first;
            // }
        }

        transaction trans{0, d, category, note, value};
        std::cout << trans << std::endl;
    }

    void options_controller::print_monthly_budget()
    {

    }
    
    void options_controller::print_help()
    {

    }
    
    void options_controller::print_categories()
    {

    }
};
