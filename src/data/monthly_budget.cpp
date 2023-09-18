#include <data/monthly_budget.hpp>

    monthly_budget::monthly_budget(float initial_budget, const date& date)
        : m_initial_budget(initial_budget)
        , m_date(date)
    { 

    }

    void monthly_budget::add_transaction(const transaction& new_transaction)
    {
        m_transactions.push_back(new_transaction);
        calculate_current_budget();
    }

    void monthly_budget::calculate_current_budget()
    {
        // m_current_budget = m_initial_budget + (incomes->get_sum() - expenses->get_sum());
    }
