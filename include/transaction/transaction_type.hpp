#pragma once

#include <string>
#include <functional>

namespace transaction
{
    class transaction_type
    {
    public:
        transaction_type(int id, const std::string& name);
        virtual ~transaction_type() = default;
        virtual int get_id() const;
        virtual const std::string& get_name() const;
        void set_name(std::string new_name);
        bool operator == (const transaction_type& other);

    protected:
        int m_id;
        std::string m_name;
    };

    class income_type : public transaction_type
    {
    public: 
        income_type(int id, const std::string& name);
    };

    class expense_type : public transaction_type
    {
    public: 
        expense_type(int id, const std::string& name);
    };

    bool operator < (const transaction_type& left, const transaction_type& right);

} // namespace transaction
