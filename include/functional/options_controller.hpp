#pragma once

#include <boost/program_options/variables_map.hpp>
#include <string>
#include <data/transaction_type.hpp>


namespace po = boost::program_options;

namespace functional 
{
    class options_controller
    {
        public:
            options_controller(const po::variables_map& variables);
            void execute_option_command();

        private:
            void add_transaction();
            void print_monthly_budget();
            void print_help();
            void print_categories();

            bool option_set(options option);
            template<typename T>
            T get_option_value(options option);


            const po::variables_map* m_variables;
    };
};