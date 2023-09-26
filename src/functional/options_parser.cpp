#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>
#include <boost/program_options/variables_map.hpp>
#include <vector>

#include <functional/options_parser.hpp>
#include <data/transaction_type.hpp>

namespace functional 
{
    options_parser::options_parser(int argc, char** argv)
    {
        m_description.add_options()

        (str_options[options::help].c_str(),   "Print short manual")
        (str_options[options::types].c_str(),  "List transaction types")
        (str_options[options::add].c_str(),    "Add new transaction to current month")
        (str_options[options::month].c_str(),  "Print list of transactions for given month")

        (str_options[options::date].c_str(),   po::value<std::string>(), "date of transaction")
        (str_options[options::category].c_str(),po::value<std::string>(), "transaction category")
        (str_options[options::note].c_str(),   po::value<std::string>(), "note added to transaction")
        (str_options[options::value].c_str(),  po::value<float>(),       "value of transaction");

        po::store(po::parse_command_line(argc, argv, m_description),m_variables);
        po::notify(m_variables);
    };

    const po::variables_map& options_parser::get_variables() const
    {
        return m_variables;
    }
}