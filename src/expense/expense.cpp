#include <expense/expense.hpp>

namespace expense
{
    expense::expense(double value_, const std::string& info_, const gregorian::date& date_)
    : value(value_), info(info_), date(date_)
    {}

    double expense::get_value() const { return value; }

    std::string expense::get_info() const { return info; }

    gregorian::date expense::get_date() const { return date; }
}
