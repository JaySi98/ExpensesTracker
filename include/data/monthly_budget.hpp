#pragma once

#include <vector>
#include <memory>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/date_clock_device.hpp>
#include <data/transaction_type.hpp>

using namespace boost::gregorian;

struct transaction
{
    int              id {0};
    date             m_date{day_clock::universal_day()};
    transaction_type type{transaction_type::unknown};
    std::string      note{""};
    float            value{0};

    friend std::ostream& operator<< (std::ostream& os, const transaction& tr);
};

struct planned_transaction
{
    transaction_type type{transaction_type::unknown};
    float sum{0};
    float current{0};

    friend std::ostream& operator<< (std::ostream& os, const planned_transaction& ptr);
};

using v_transaction = std::vector<transaction>; 
using v_planned = std::vector<planned_transaction>; 

v_planned create_default_planned_incomes();
v_planned create_default_planned_expenses();

struct monthly_budget
{    
public:
    void add_transaction(const transaction& new_transaction);
    void remove_transaction(int id);
    const v_transaction& get_transactions();

    float m_initial_budget{0};
    float m_current_budget{0};
    date m_date{day_clock::universal_day()};
    v_planned m_planned_expenses{create_default_planned_expenses()};
    v_planned m_planned_incomes{create_default_planned_incomes()};

private:
    void calculate_current_budget();

    v_transaction m_transactions{};
};

