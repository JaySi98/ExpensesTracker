#include <transaction.hpp>
#include "transaction_type.hpp"

transaction::transaction(date d ,
        transaction_type type, 
        std::string note,
        int value)
    : m_date(d)
    , m_type(type)
    , m_note(note)
    , m_value(value)
{
}

std::ostream& operator<< (std::ostream& os, const transaction& tr)
{
    os << tr.m_date << " | " << tr.m_value << " | " 
       << str_tran_type.at(tr.m_type) << " | " << tr.m_note;

    return os;
}
