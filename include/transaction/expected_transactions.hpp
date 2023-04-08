#pragma once

#include <map>
#include <memory>
#include <transaction/transaction.hpp>

namespace transaction
{
    class expected_transactions
    {
        using mapped_incomes  = std::map<income_type, float>; 
        using mapped_expanses = std::map<expense_type, float>;

    public:
        expected_transactions() = default;                                                    
        expected_transactions(const mapped_incomes& incomes, const mapped_expanses& expenses);
         
        bool add_new_transaction(income_type type, float expected_value);
        bool add_new_transaction(expense_type type, float expected_value);        
        bool update_transaction(income_type type, float new_value);
        bool update_transaction(expense_type type, float new_value);

        const mapped_incomes& get_expected_incomes() const; 
        const mapped_expanses& get_expected_expenses() const;
                
    private:     
        mapped_incomes  m_assumed_incomes;
        mapped_expanses m_assumed_expenses;
    };
}

