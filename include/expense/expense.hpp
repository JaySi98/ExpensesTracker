#pragma once

#include <string>
#include <stdint.h>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost;

namespace expense
{
    class expense
    {
    public:
        expense(double value_, const std::string& info_, const gregorian::date& date_);

        double get_value() const;
        std::string get_info() const;
        gregorian::date get_date() const;

    private:
        double value;
        std::string info;
        gregorian::date date;
    };    
} // namespace expense
