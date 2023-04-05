#include <transaction/transaction.hpp>

namespace transaction
{   
    static int generate_transaction_id()
    {
        static int i = 0;
        return i++;
    }

    transaction_type::transaction_type(int id_, const std::string& name_)
        : id(id_), name(name_) 
    {}

    transaction::transaction(double value_, const std::string& info_, const gregorian::date& day_)
    : value(value_), info(info_), day(day_), id(generate_transaction_id())
    {}

    double transaction::get_value() const { return value; }

    std::string transaction::get_info() const { return info; }

    gregorian::date transaction::get_day() const { return day; }
}
