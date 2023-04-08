#pragma once

#include <vector>
#include <transaction/expected_transactions.hpp>

namespace budget
{
    class monthly_budget
    {
        // TODO - get_incomes(), get_expanses()
        // TODO - calculate_current_budget
        // TODO - change -m_month to m_month_year
    public:
        monthly_budget(float initial_budget, int month, assumed_transactions assumed)
            : m_initial_budget(initial_budget)
            , m_current_budget(initial_budget)
            , m_month(month) 
            , m_assumed(assumed)
        {}

        void add_income(const income& new_income) {m_incomes.push_back(new_income);}
        void add_expense(const expense& new_expense) {m_expenses.push_back(new_expense);}

    private:
        std::vector<income> m_incomes;
        std::vector<expense> m_expenses;
        assumed_transactions m_assumed;
        float m_initial_budget;
        float m_current_budget;
        int m_month;
    };
} // namespace budget

