#pragma once

#include <vector>
#include <map>
#include <memory>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/date_clock_device.hpp>
#include <data/transaction_type.hpp>

using namespace boost::gregorian;

struct transaction
{
    int id {0};
    date m_date{day_clock::universal_day()};
    transaction_category category{transaction_category::unknown};
    std::string note{""};
    float value{0};

    friend std::ostream& operator<< (std::ostream& os, const transaction& tr);
};

struct planned_transaction
{
    transaction_type type{transaction_type::expense};
    float sum{0};
    float current{0};

    friend std::ostream& operator<< (std::ostream& os, const planned_transaction& ptr);
};

using v_transaction = std::vector<transaction>; 
using map_planned = std::map<transaction_category, planned_transaction>;

map_planned create_default_planned();

struct monthly_budget
{
public:
    void add_transaction(transaction new_transaction);
    void remove_transaction(int id);
    const v_transaction& get_transactions();

    float initial_budget{0};
    float current_budget{0};
    date m_date{day_clock::universal_day()};
    map_planned planned{create_default_planned()};

private:
    void calculate_current_budget();

    v_transaction m_transactions{};
};

