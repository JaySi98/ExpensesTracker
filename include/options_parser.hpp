#pragma once

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options.hpp>
#include <boost/program_options/variables_map.hpp>
#include <string>

#include <transaction.hpp>
#include "transaction_type.hpp"

namespace po = boost::program_options;

class options_parser
{
    public:
        options_parser(int argc, char** argv);
        ~options_parser() = default;

        const po::variables_map& get_variables() const;

    private:
        po::options_description m_description;
        po::variables_map m_variables;
};

