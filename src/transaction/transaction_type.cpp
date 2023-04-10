#include <transaction/transaction_type.hpp>

namespace transaction
{
    transaction_type::transaction_type(int id, const std::string& name)
        : m_id(id), m_name(name)
    { }        

    int transaction_type::get_id() const 
    {return m_id;}
    
    const std::string& transaction_type::get_name() const 
    {return m_name;}

    void transaction_type::set_name(std::string new_name) 
    {m_name = new_name;}

    bool transaction_type::operator == (const transaction_type& other)
    { return (m_id == other.m_id);}

    income_type::income_type(int id, const std::string& name)
        : transaction_type(id, name)
    {}

    expense_type::expense_type(int id, const std::string& name)
        : transaction_type(id, name)
    { }

    bool operator < (const transaction_type& left, const transaction_type& right)
    { return (left.get_id() < right.get_id());}
}