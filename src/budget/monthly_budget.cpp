#include <budget/monthly_budget.hpp>

namespace budget
{
    monthly_budget::monthly_budget(float initial_budget, const gregorian::date& date, const expected_transactions& expected)
        : m_initial_budget(initial_budget)
        , m_current_budget(initial_budget)
        , m_month_year(date) 
        , m_expected(new expected_transactions(expected))
    { }

    void monthly_budget::add_income(const income& new_income) 
    {m_incomes.push_back(new_income);}

    void monthly_budget::add_expense(const expense& new_expense) 
    {m_expenses.push_back(new_expense);}
    
} // namespace budget
