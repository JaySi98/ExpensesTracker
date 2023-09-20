#include <data/monthly_budget.hpp>

    std::ostream& operator<< (std::ostream& os, const transaction& tr)
    {
        os << tr.m_date << " | " << tr.value << " | " << str_tran_type.at(tr.type) << " | " << tr.note;
        return os;
    }

    std::ostream& operator<< (std::ostream& os, const planned_transaction& ptr)
    {
        os << str_tran_type.at(ptr.type) << " | " << ptr.sum  << " | " << ptr.current;
        return os;
    }

    monthly_budget::monthly_budget(
            float initial_budget, 
            const date& date, 
            const v_planned& planned_incomes,  
            const v_planned& planned_expenses
        )
        : m_initial_budget(initial_budget)
        , m_current_budget(initial_budget)
        , m_planned_expenses(planned_expenses)
        , m_planned_incomes(planned_incomes)
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
