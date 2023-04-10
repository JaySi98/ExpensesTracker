#pragma once

#include <map>
#include <memory>
#include <transaction/transaction.hpp>


namespace transaction
{
    class planned_transactions
    {
        using mapped_expected = std::map<transaction_type, float>; 

    public:
        planned_transactions() = default;                                                    
         
        // bool add_new_transaction(transaction_type type, float expected_value);
        // bool update_transaction(transaction_type type, float new_value);
        std::pair<transaction_type, float> get_transaction(transaction_type type) const;
        float get_sum() const;

    private:     
        void calculate_sum_planned();
        
        mapped_expected map_planned;
        float m_sum_planned;
    };
}

// namespace transaction
// {
//     class expected_transactions
//     {
//         using mapped_incomes  = std::map<income_type, float>; 
//         using mapped_expanses = std::map<expense_type, float>;

//     public:
//         expected_transactions() = default;                                                    
//         expected_transactions(const mapped_incomes& incomes, const mapped_expanses& expenses);
         
//         bool add_new_transaction(income_type type, float expected_value);
//         bool add_new_transaction(expense_type type, float expected_value);        
//         bool update_transaction(income_type type, float new_value);
//         bool update_transaction(expense_type type, float new_value);

//         const mapped_incomes& get_expected_incomes() const; 
//         const mapped_expanses& get_expected_expenses() const;

//         std::pair<bool, float> get_transaction_value(income_type type) const;
//         std::pair<bool, float> get_transaction_value(expense_type type) const;

//         float get_sum_expected_incomes() const;
//         float get_sum_expected_expenses() const;

//     private:     
//         void calculate_sum_incomes();
//         void calculate_sum_expenses();
//         mapped_incomes  m_assumed_incomes;
//         mapped_expanses m_assumed_expenses;
//         float m_sum_incomes;
//         float m_sum_expenses;
//     };
// }

