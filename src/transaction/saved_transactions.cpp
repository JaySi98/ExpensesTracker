#include <transaction/saved_transactions.hpp>
#include <algorithm>

namespace transaction
{
    void saved_transactions::add_new_transaction(const transaction& new_transaction)
    {
        m_transactions.push_back(new_transaction);
        calculate_sum();
    }

    void saved_transactions::remove_transaction(int transaction_id)
    {
        auto result = std::find_if(std::begin(m_transactions), std::end(m_transactions), [transaction_id](const transaction& trans)
        {
            return trans.id == transaction_id;
        });

        if(result != m_transactions.end())
        {
            m_transactions.erase(result);
            calculate_sum();
        }
        else 
            throw std::logic_error("transaction not found");
    }

    std::map<transaction_type, float> saved_transactions::get_sum_by_type()
    {
        std::map<transaction_type, float> sums;
        
        for(transaction trans : m_transactions)
        {
            if(sums.find(*trans.type.get()) != sums.end())
            {
                sums[*trans.type.get()] += trans.value; 
            }
            else
            {
                sums[*trans.type.get()] = trans.value; 
            }
        }        

        return sums;
    }

    void saved_transactions::calculate_sum()
    {
        float new_sum = 0;
        for(transaction trans : m_transactions)
        {
            new_sum += trans.value;
        }

        m_sum = new_sum;
    }

    const std::vector<transaction>& saved_transactions::get_transactions() const
    { return m_transactions; }

    float saved_transactions::get_sum() const
    { return m_sum;}

} // namespace transaction
