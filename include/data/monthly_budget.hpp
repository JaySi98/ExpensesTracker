#pragma once

#include <vector>
#include <memory>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <data/transaction.hpp>

using namespace boost::gregorian;

struct planned_transaction
{
    transaction_type type = transaction_type::unknown;
    float sum = 0;
};

class monthly_budget
{    
public:
    monthly_budget(float initial_budget, const date& date);
    void add_transaction(const transaction& new_transaction);

private:
    void calculate_current_budget();

    float m_initial_budget;
    float m_current_budget;
    date m_date;

    std::vector<transaction> m_transactions;
};

