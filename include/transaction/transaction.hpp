#pragma once

#include <string>
#include <memory>
#include <stdint.h>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <transaction/transaction_type.hpp>

using namespace boost;

namespace transaction
{
    class transaction
    {
        using p_type = std::shared_ptr<transaction_type>; 

    public:
        transaction() = default;
        transaction(int id_, const std::string& note_, const gregorian::date& day_, float value_, const transaction_type& type_)
            : id(id_)
            , note(note_)
            , day(day_)
            , value(value_)
            , type(new transaction_type(type_)) 
        { }
        virtual ~transaction() = default;

        int             id;
        std::string     note;
        gregorian::date day;
        float           value;        
        p_type          type;
    };

    class income : public transaction
    {
    public:
        income() = default;
        income(int id_, const std::string& note_, const gregorian::date& day_, float value_, const transaction_type& type_)
            : transaction(id_, note_, day_, value_, type_)
        {}
    };


    class expense : public transaction
    {
    public:
        expense() = default;
        expense(int id_, const std::string& note_, const gregorian::date& day_, float value_, const transaction_type& type_)
            : transaction(id_, note_, day_, value_, type_)
        {}
    };

} // namespace transaction



// namespace transaction
// {
//     class transaction
//     {
//         using p_type = std::shared_ptr<transaction_type>; 
//     public:
//         transaction(int id, const std::string& note, const gregorian::date& day, float value, 
//                 const transaction_type& new_type);
//         virtual ~transaction() = default;

//         std::string get_note()  const;
//         int         get_id()    const;
//         float       get_value() const;
//         const gregorian::date&    get_day()   const;
//         const p_type get_type() const;

//         void set_note(const std::string& new_note);
//         void set_value(float new_value);
//         void set_day(const gregorian::date& new_day);
//         void set_type(const transaction_type& new_type);

//     protected:
//         int             m_id;
//         std::string     m_note;
//         float           m_value;        
//         gregorian::date m_day;
//         p_type          m_type;
//     };

//     class income : public transaction
//     {
//     public:
//         income(int id, const std::string& note, const gregorian::date& day, float value, 
//                 const transaction_type& new_type);
//     };


//     class expense : public transaction
//     {
//     public:
//         expense(int id, const std::string& note, const gregorian::date& day, float value, 
//                 const transaction_type& new_type);

//     };

// } // namespace transaction
