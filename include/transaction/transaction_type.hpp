#pragma once

#include <string>
#include <functional>

namespace transaction
{
    class transaction_type
    {
    public:
        transaction_type(int id, const std::string& name)
            : m_id(id), m_name(name)
        { }        

        virtual ~transaction_type() = default;

        virtual int get_id() const 
        {return m_id;}
        
        virtual const std::string& get_name() const 
        {return m_name;}

        void set_name(std::string new_name) 
        {m_name = new_name;}

        bool operator == (const transaction_type& other)
        { return (m_id == other.m_id);}

        // bool operator < (const transaction_type& other)
        // { return (m_id < other.m_id);}

    protected:
        int m_id;
        std::string m_name;
    };

    class income_type : public transaction_type
    {
    public: 
        income_type(int id, const std::string& name)
            : transaction_type(id, name)
        {}
    };

    class expense_type : public transaction_type
    {
    public: 
        expense_type(int id, const std::string& name)
            : transaction_type(id, name)
        {}
    };

    bool operator < (const transaction_type& left, const transaction_type& right)
    { return (left.get_id() < right.get_id());}

} // namespace transaction
