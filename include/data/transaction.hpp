#pragma once

#include <string>
#include <stdint.h>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/date_clock_device.hpp>
#include <data/transaction_type.hpp>

using namespace boost::gregorian;

class transaction 
{
    public:
        transaction(date d = day_clock::universal_day() ,
                    transaction_type type = transaction_type::unknown, 
                    std::string note = "",
                    int value = 0);
        ~transaction() = default;
        friend std::ostream& operator<< (std::ostream& os, const transaction& tr);

    private:
        date             m_date;
        int              m_value;
        transaction_type m_type;
        std::string      m_note;
};
