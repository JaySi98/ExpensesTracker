#pragma once

#include <vector>
#include <memory>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <transaction/expected_transactions.hpp>

namespace budget
{
    using namespace transaction;

    class monthly_budget
    {        
        using p_expected = std::shared_ptr<expected_transactions>;
        using p_incomes  = std::shared_ptr<std::vector<income>>;
        using p_expenses = std::shared_ptr<std::vector<expense>>;
        
    public:
        monthly_budget(float initial_budget, const gregorian::date& date, const expected_transactions& expected);

        void add_income(const income& new_income);
        void add_expense(const expense& new_expense);

        void set_initial_budget(float new_value);
        float get_initial_budget() const;
        float get_current_budget() const;
        gregorian::date get_date() const;
        void set_date(const gregorian::date& new_date);

        p_incomes  get_incomes()   const;
        p_expenses get_expenses()  const;
        p_expected get_expected_transactions() const;

    private:
        void calculate_current_budget();

        p_incomes  m_incomes;
        p_expenses m_expenses;
        gregorian::date m_month_year;
        p_expected m_expected;
        float m_initial_budget;
        float m_current_budget;
    };
} // namespace budget

