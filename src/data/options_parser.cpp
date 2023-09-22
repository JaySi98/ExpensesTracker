#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>
#include <boost/program_options/variables_map.hpp>
#include <data/options_parser.hpp>
#include <data/transaction_type.hpp>

#include <vector>

options_parser::options_parser(int argc, char** argv)
{
    m_description.add_options()
        ("help,H", "")
        ("types,T", "")
        ("add,A", "Add new transaction to current month")
        ("month,M", "Print list of transactions for given month")

        ("date",    po::value<std::string>(),   "date of transaction")
        ("cat",     po::value<std::string>(),   "transaction category")
        ("note",    po::value<std::string>(),   "note added to transaction")
        ("value",   po::value<float>(),         "value of transaction");
   
    po::store(po::parse_command_line(argc, argv, m_description),m_variables);
    po::notify(m_variables);
};

const po::variables_map& options_parser::get_variables() const
{
    return m_variables;
}
