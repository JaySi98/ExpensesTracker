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
