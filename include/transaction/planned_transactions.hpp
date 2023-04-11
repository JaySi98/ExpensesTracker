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
         
        bool add_new_transaction(transaction_type type, float expected_value);
        bool update_transaction(transaction_type type, float new_value);
        std::pair<transaction_type, float> get_transaction(transaction_type type) const;
        float get_sum() const;

    private:     
        void calculate_sum_planned();
        
        mapped_expected map_planned;
        float m_sum_planned;
    };
}
