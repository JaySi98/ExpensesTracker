#include <transaction/transaction.hpp>


namespace transaction
{
    static int generate_id()
    {
        static int i = 0;
        return i++;
    }

    // TRANSACTION
    transaction::transaction(const std::string& note, const gregorian::date& day, float value)
        : m_note(note), m_day(day), m_value(value), m_id(generate_id()) 
    { }

    std::string transaction::get_note()  const {return m_note;}
    int         transaction::get_id()    const {return m_id;}
    float       transaction::get_value() const {return m_value;}
    gregorian::date transaction::get_day() const {return m_day;}

    // INCOME
    income::income(const std::string& note, const gregorian::date& day, float value, const income_type& type)
        : transaction(note, day, value), m_type(type) 
    { }      

    income_type income::get_type() const {return m_type;}

    // EXPENSE
    expense::expense(const std::string& note, const gregorian::date& day, float value, const expense_type& type)
        : transaction(note, day, value), m_type(type) 
    {}

    expense_type expense::get_type() const {return m_type;}

} // namespace transaction
