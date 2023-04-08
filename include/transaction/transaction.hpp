#pragma once

#include <string>
#include <stdint.h>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost;

    // TODO add operators
    // TODO add proper enums

namespace transaction
{
    enum class income_type
    {
        SALARY,
        INVESTMENTS,
        OTHER
    };

    enum class expense_type
    {
        RENT,
        FOOD,
        OTHER
    };

    class transaction
    {
    public:
        transaction(const std::string& note, const gregorian::date& day, float value);
        virtual ~transaction() = default;

        std::string get_note()  const;
        int         get_id()    const;
        float       get_value() const;
        gregorian::date get_day() const;

    protected:
        int         m_id;
        std::string m_note;
        float       m_value;        
        gregorian::date m_day;
    };

    class income : public transaction
    {
    public:
        income(const std::string& note, const gregorian::date& day, float value, const income_type& type);        
        income_type get_type() const;

    private:
        income_type m_type;
    };


    class expense : public transaction
    {
    public:
        expense(const std::string& note, const gregorian::date& day, float value, const expense_type& type);
        expense_type get_type() const;

    private:
        expense_type m_type;
    };

} // namespace transaction
