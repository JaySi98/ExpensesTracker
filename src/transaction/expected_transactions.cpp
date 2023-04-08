#include <transaction/expected_transactions.hpp>

namespace transaction
{

    expected_transactions::expected_transactions(const mapped_incomes& incomes, const mapped_expanses& expenses)
        : m_assumed_incomes(incomes), m_assumed_expenses(expenses) 
    { }

    bool expected_transactions::add_new_transaction(income_type type, float expected_value)
    {
        return m_assumed_incomes.emplace(std::pair<income_type, float>(type, expected_value)).second;
    }                                                                    

    bool expected_transactions::add_new_transaction(expense_type type, float expected_value)
    {
        return m_assumed_expenses.emplace(std::pair<expense_type, float>(type, expected_value)).second;
    }
    
    bool expected_transactions::update_transaction(income_type type, float new_value)
    {
        auto iter = m_assumed_incomes.find(type);

        if(iter != m_assumed_incomes.end())
        {
            iter->second = new_value;
            return true;
        }

        return false;
    }

    bool expected_transactions::update_transaction(expense_type type, float new_value)
    {
        auto iter = m_assumed_expenses.find(type);

        if(iter != m_assumed_expenses.end())
        {
            iter->second = new_value;
            return true;
        }

        return false;
    }

    const expected_transactions::mapped_incomes&  expected_transactions::get_expected_incomes()  const{return m_assumed_incomes;}
    const expected_transactions::mapped_expanses& expected_transactions::get_expected_expenses() const{return m_assumed_expenses;}
}