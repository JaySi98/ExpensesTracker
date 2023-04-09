#pragma once

#include <string>
#include <functional>

namespace transaction
{
    class transacation_type
    {
    public:
        transacation_type(std::function<int(void)> id_generator, const std::string& name)
            : m_id(id_generator()), m_name(name)
        { }        

        virtual ~transacation_type() = default;

        virtual int get_id() const 
        {return m_id;}
        
        virtual const std::string& get_name() const 
        {return m_name;}

        void set_name(std::string new_name) 
        {m_name = new_name;}

    protected:
        int m_id;
        std::string m_name;
    };

    class income_type : public transacation_type
    {
    public: 
        income_type(std::function<int(void)> id_generator, const std::string& name)
            : transacation_type(id_generator, name)
        {}
    };

    class expense_type : public transacation_type
    {
    public: 
        expense_type(std::function<int(void)> id_generator, const std::string& name)
            : transacation_type(id_generator, name)
        {}
    };

} // namespace transaction
