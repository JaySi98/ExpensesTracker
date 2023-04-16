#include <budget/monthly_budget.hpp>

namespace budget
{
    monthly_budget::monthly_budget(float initial_budget, const gregorian::date& date)
        : m_initial_budget(initial_budget)
        , m_date(date)
        , incomes(new saved_transactions)
        , expenses(new saved_transactions)
    { }

    monthly_budget::monthly_budget(float initial_budget, const gregorian::date& date, const planned_transactions& planned_incomes_, 
                const planned_transactions& planned_expenses_)
        : m_initial_budget(initial_budget), m_date(date)
        , planned_incomes(new planned_transactions(planned_incomes_))
        , planned_expenses(new planned_transactions(planned_expenses_))
        , incomes(new saved_transactions)
        , expenses(new saved_transactions)
    { 
        calculate_current_budget();
    }

    void monthly_budget::add_income(const income& new_income)
    {
        incomes->add_new_transaction(new_income);
        calculate_current_budget();
    }

    void monthly_budget::add_expense(const expense& new_expense)
    {
        expenses->add_new_transaction(new_expense);
        calculate_current_budget();
    }

    void monthly_budget::calculate_current_budget()
    {
        m_current_budget = m_initial_budget + (incomes->get_sum() - expenses->get_sum());
    }

    void monthly_budget::set_initial_budget(float new_value)
    {
        m_initial_budget = new_value;
        calculate_current_budget(); 
    }

    void monthly_budget::set_date(const gregorian::date& new_date)
    { m_date = new_date; }

    std::shared_ptr<saved_transactions> monthly_budget::get_incomes()
    { return incomes; }

    std::shared_ptr<saved_transactions> monthly_budget::get_expenses()
    { return expenses; }

    std::shared_ptr<planned_transactions> monthly_budget::get_planned_incomes()
    { return planned_incomes; }

    std::shared_ptr<planned_transactions> monthly_budget::get_planned_expenses()
    { return planned_expenses; }

    float monthly_budget::get_initial_budget() const
    { return m_initial_budget; }
    
    float monthly_budget::get_current_budget() const
    { return m_current_budget; }

    gregorian::date monthly_budget::get_date() const
    { return m_date; }

} // namespace budget
