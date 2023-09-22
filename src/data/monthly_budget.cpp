#include <data/monthly_budget.hpp>

    map_planned create_default_planned()
    {
        map_planned planned{
            {transaction_category::unknown,                 planned_transaction{transaction_type::income,0,0}},
            {transaction_category::salary,                  planned_transaction{transaction_type::income,0,0}},
            {transaction_category::sales,                   planned_transaction{transaction_type::income,0,0}},
            {transaction_category::stocks,                  planned_transaction{transaction_type::income,0,0}},
            {transaction_category::other_incomes,           planned_transaction{transaction_type::income,0,0}},

            {transaction_category::unknown,                 planned_transaction{transaction_type::expense,0,0}},
            {transaction_category::bills,                   planned_transaction{transaction_type::expense,0,0}},
            {transaction_category::rent,                    planned_transaction{transaction_type::expense,0,0}},
            {transaction_category::insurances,              planned_transaction{transaction_type::expense,0,0}},
            {transaction_category::subscriptions,           planned_transaction{transaction_type::expense,0,0}},
            {transaction_category::food,                    planned_transaction{transaction_type::expense,0,0}},
            {transaction_category::transport,               planned_transaction{transaction_type::expense,0,0}},
            {transaction_category::house_maintenance,       planned_transaction{transaction_type::expense,0,0}},
            {transaction_category::social_outings,          planned_transaction{transaction_type::expense,0,0}},
            {transaction_category::gym,                     planned_transaction{transaction_type::expense,0,0}},
            {transaction_category::clothes,                 planned_transaction{transaction_type::expense,0,0}},
            {transaction_category::appearance_health,       planned_transaction{transaction_type::expense,0,0}},
            {transaction_category::furniture_equipment,     planned_transaction{transaction_type::expense,0,0}},
            {transaction_category::personal_development,    planned_transaction{transaction_type::expense,0,0}},
            {transaction_category::cards,                   planned_transaction{transaction_type::expense,0,0}},
            {transaction_category::crap,                    planned_transaction{transaction_type::expense,0,0}},

        };
        return planned;
    }

    std::ostream& operator<< (std::ostream& os, const transaction& tr)
    {
        os << tr.id  << " | " << tr.m_date << " | " << tr.value << " | " << str_tran_cat.at(tr.category) << " | " << tr.note;
        return os;
    }

    std::ostream& operator<< (std::ostream& os, const planned_transaction& ptr)
    {
        os << " | " << ptr.sum  << " | " << ptr.current;
        return os;
    }

    void monthly_budget::add_transaction(const transaction& new_transaction)
    {
        m_transactions.push_back(new_transaction);
        planned[new_transaction.category].current += new_transaction.value;    
        calculate_current_budget();
    }

    void monthly_budget::remove_transaction(int id)
    {
        std::remove_if(m_transactions.begin(),m_transactions.end(), [&id](const transaction& tr){
            return tr.id == id;
        });

        // TODO
        // planned[new_transaction.type].current -= new_transaction.value;
        calculate_current_budget();
    }

    const v_transaction& monthly_budget::get_transactions()
    {
        return m_transactions;
    }

    void monthly_budget::calculate_current_budget()
    {
        float transaction_sum = 0;
        std::for_each(m_transactions.begin(), m_transactions.end(), [&transaction_sum](const transaction& tr){
            transaction_sum += tr.value;
        });

        current_budget = initial_budget + transaction_sum;
    }
