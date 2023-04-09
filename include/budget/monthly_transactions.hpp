#pragma once

#include <vector>
#include <memory>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <transaction/expected_transactions.hpp>

namespace transaction
{
    class monthly_transactions
    {
    public:
        monthly_transactions() = default;
        virtual ~monthly_transactions() = default;


    protected:

    };

    class monthly_incomes : public monthly_transactions
    {
        using map_exp_incomes  = std::map<income_type, float>; 
        using vec_incomes      = std::vector<income>;

    public:
        monthly_incomes();
    
    private:
        map_exp_incomes m_expected_incomes;
        vec_incomes     m_saved_incomes;
    };


    class monthly_expenses : public monthly_transactions
    {
        using map_exp_expenses  = std::map<expense_type, float>; 
        using vec_expenses      = std::vector<expense>;

    public:
        monthly_expenses();
    
    private:
        map_exp_expenses m_expected_expenses;
        vec_expenses     m_saved_expenses;
    };
}