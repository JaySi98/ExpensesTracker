#pragma once

#include <string>
#include <stdint.h>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost;

namespace transaction
{
    class transaction_type
    {
    public:
        transaction_type(int id_, const std::string& name_);
    private:
        std::string name;
        int id;
    };
    
    class transaction
    {
    public:
        transaction(double value_, const std::string& info_, const gregorian::date& day_);

        double get_value() const;
        std::string get_info() const;
        gregorian::date get_day() const;

    protected:
        int id;
        double value;
        std::string info;
        gregorian::date day;
    };    
} // namespace expense
