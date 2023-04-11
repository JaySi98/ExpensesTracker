#pragma once

#include <map>
#include <memory>
#include <vector>
#include <transaction/transaction.hpp>

namespace transaction
{
    class saved_transactions
    {
    public:
        saved_transactions() = default;
        void add_new_transaction(const transaction& new_transaction);
        void remove_transaction(int transaction_id);
        const std::vector<transaction>& get_transactions() const;
        std::map<transaction_type, float> get_sum_by_type();
        float get_sum() const;

    private:
        void calculate_sum();

        std::vector<transaction>  m_transactions;
        float m_sum;
    };
} // namespace transaction
