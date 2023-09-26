#pragma once

#include <boost/program_options/variables_map.hpp>
#include <string>

namespace po = boost::program_options;

namespace functional 
{
    class options_controller
    {
        public:
            options_controller(const po::variables_map& variables);
            void execute_option_command();

        private:
            const po::variables_map* m_variables;
    };
};