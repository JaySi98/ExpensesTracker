#include <transaction/planned_transactions.hpp>

namespace transaction
{
    bool planned_transactions::add_new_transaction(transaction_type type, float expected_value)
    {
        if(map_planned.emplace(std::pair<transaction_type, float>(type, expected_value)).second)
        {
            calculate_sum_planned();
            return true;
        }

        return false;
    }

    bool planned_transactions::update_transaction(transaction_type type, float new_value)
    {
        auto iter = map_planned.find(type);

        if(iter != map_planned.end())
        {
            iter->second = new_value;
            calculate_sum_planned();
            return true;
        }

        return false;
    }

    std::pair<transaction_type, float> planned_transactions::get_transaction(transaction_type type) const
    {
        auto iter = map_planned.find(type);

        if(iter != map_planned.end())
        {
            return *iter; 
        }

        // in case it doesnt contain
        throw std::logic_error("type missing in planned transactions");
    }

    void planned_transactions::calculate_sum_planned()
    {
        float sum = 0;
        for(std::pair<transaction_type, float> pair : map_planned)
        {
            sum += pair.second;
        }
        m_sum_planned = sum;
    }

    float planned_transactions::get_sum() const
    { return m_sum_planned; }
}

// namespace transaction
// {

//     expected_transactions::expected_transactions(const mapped_incomes& incomes, const mapped_expanses& expenses)
//         : m_assumed_incomes(incomes)
//         , m_assumed_expenses(expenses) 
//     { 
//         calculate_sum_incomes();
//         calculate_sum_expenses();
//     }

//     bool expected_transactions::add_new_transaction(income_type type, float expected_value)
//     {
//         if(m_assumed_incomes.emplace(std::pair<income_type, float>(type, expected_value)).second)
//         {
//             calculate_sum_incomes();
//             return true;
//         }

//         return false;
//     }                                                                    

//     bool expected_transactions::add_new_transaction(expense_type type, float expected_value)
//     {
//         if(m_assumed_expenses.emplace(std::pair<expense_type, float>(type, expected_value)).second)
//         {
//             calculate_sum_expenses();
//             return true;
//         }

//         return false;
//     }
    
//     bool expected_transactions::update_transaction(income_type type, float new_value)
//     {
//         auto iter = m_assumed_incomes.find(type);

//         if(iter != m_assumed_incomes.end())
//         {
//             iter->second = new_value;
//             calculate_sum_incomes();
//             return true;
//         }

//         return false;
//     }

//     bool expected_transactions::update_transaction(expense_type type, float new_value)
//     {
//         auto iter = m_assumed_expenses.find(type);

//         if(iter != m_assumed_expenses.end())
//         {
//             iter->second = new_value;
//             calculate_sum_expenses();
//             return true;
//         }

//         return false;
//     }

//     const expected_transactions::mapped_incomes&  expected_transactions::get_expected_incomes()  const
//     {return m_assumed_incomes;}

//     const expected_transactions::mapped_expanses& expected_transactions::get_expected_expenses() const
//     {return m_assumed_expenses;}

//     std::pair<bool, float> expected_transactions::get_transaction_value(income_type type) const
//     {
//         auto iter = m_assumed_incomes.find(type);

//         if(iter != m_assumed_incomes.end())
//         {
//             return std::pair<bool, float>(true, iter->second); 
//         }

//         // in case it doesnt contain
//         return std::pair<bool, float>(false, 0);
//     }

//     std::pair<bool, float> expected_transactions::get_transaction_value(expense_type type) const
//     {
//         auto iter = m_assumed_expenses.find(type);

//         if(iter != m_assumed_expenses.end())
//         {
//             return std::pair<bool, float>(true, iter->second); 
//         }

//         // in case it doesnt contain
//         return std::pair<bool, float>(false, 0);
//     }

//     void expected_transactions::calculate_sum_incomes()
//     {
//         float sum = 0;
//         for(std::pair<income_type, float> pair : m_assumed_incomes)
//         {
//             sum += pair.second;
//         }
//         m_sum_incomes = sum;
//     }

//     void expected_transactions::calculate_sum_expenses()
//     {
//         float sum = 0;
//         for(std::pair<expense_type, float> pair : m_assumed_expenses)
//         {
//             sum += pair.second;
//         }
//         m_sum_expenses = sum;
//     }

//     float expected_transactions::get_sum_expected_incomes() const
//     { return m_sum_incomes; }

//     float expected_transactions::get_sum_expected_expenses() const
//     { return m_sum_expenses; }
// }