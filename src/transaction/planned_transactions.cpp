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
