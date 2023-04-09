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
        saved_transactions(const std::vector<income>& incomes, const std::vector<expense>& expenses);

    private:
        std::vector<income>  m_incomes;
        std::vector<expense> m_expenses;        
    };
} // namespace transaction
