#pragma once

#include <string>
#include <stdint.h>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost;

class Expense
{
public:
    Expense();
    

private:
    double value;
    std::string note;
    gregorian::date date;
};