#pragma once

#include <vector>
#include <memory>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <transaction/planned_transactions.hpp>
#include <transaction/saved_transactions.hpp>

namespace budget
{
    using namespace transaction;

    class monthly_budget
    {        
        using p_planned  = std::shared_ptr<planned_transactions>;
        using p_saved    = std::shared_ptr<saved_transactions>;
        
    public:
        monthly_budget(float initial_budget, const gregorian::date& date);
        monthly_budget(float initial_budget, const gregorian::date& date, const planned_transactions& planned_incomes, 
                    const planned_transactions& planned_expenses);

        void add_income(const income& new_income);
        void add_expense(const expense& new_expense);

        std::shared_ptr<saved_transactions>  get_incomes();
        std::shared_ptr<saved_transactions>  get_expenses();
        std::shared_ptr<planned_transactions> get_planned_incomes();
        std::shared_ptr<planned_transactions> get_planned_expenses();

        void  set_initial_budget(float new_value);
        float get_initial_budget() const;
        float get_current_budget() const;
        void  set_date(const gregorian::date& new_date);
        gregorian::date get_date() const;

    private:
        void calculate_current_budget();

        float m_initial_budget;
        gregorian::date m_date;
        float m_current_budget;

        p_saved incomes;
        p_saved expenses;
        p_planned planned_incomes;
        p_planned planned_expenses;
    };
} // namespace budget

