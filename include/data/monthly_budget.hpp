#pragma once

#include <vector>
#include <memory>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/date_clock_device.hpp>
#include <data/transaction_type.hpp>

using namespace boost::gregorian;

struct transaction
{
    date             m_date = day_clock::universal_day();
    transaction_type type = transaction_type::unknown;
    std::string      note = "";
    float            value = 0;

    friend std::ostream& operator<< (std::ostream& os, const transaction& tr);
};

struct planned_transaction
{
    transaction_type type = transaction_type::unknown;
    float sum = 0;
    float current = 0;

    friend std::ostream& operator<< (std::ostream& os, const planned_transaction& ptr);
};

using v_transaction = std::vector<transaction>; 
using v_planned = std::vector<planned_transaction>; 

class monthly_budget
{    
public:
    monthly_budget(float initial_budget, const date& date, const v_planned& planned_incomes,  const v_planned& planned_expenses);
    void add_transaction(const transaction& new_transaction);

private:
    void calculate_current_budget();

    float m_initial_budget;
    float m_current_budget;
    v_transaction m_transactions;
    v_planned m_planned_expenses;
    v_planned m_planned_incomes;
    date m_date;
};

