#include <data/monthly_budget.hpp>

    v_planned create_default_planned_incomes()
    {
        v_planned incomes{
            planned_transaction{transaction_type::unknown,0,0},
            planned_transaction{transaction_type::salary,0,0},
            planned_transaction{transaction_type::sales,0,0},
            planned_transaction{transaction_type::stocks,0,0},
            planned_transaction{transaction_type::other_incomes,0,0},
        };
        return incomes;
    }

    v_planned create_default_planned_expenses()
    {
        v_planned expenses{
            planned_transaction{transaction_type::unknown,0,0},
            planned_transaction{transaction_type::bills,0,0},
            planned_transaction{transaction_type::rent,0,0},
            planned_transaction{transaction_type::insurances,0,0},
            planned_transaction{transaction_type::subscriptions,0,0},
            planned_transaction{transaction_type::food,0,0},
            planned_transaction{transaction_type::transport,0,0},
            planned_transaction{transaction_type::house_maintenance,0,0},
            planned_transaction{transaction_type::social_outings,0,0},
            planned_transaction{transaction_type::gym,0,0},
            planned_transaction{transaction_type::clothes,0,0},
            planned_transaction{transaction_type::appearance_health,0,0},
            planned_transaction{transaction_type::furniture_equipment,0,0},
            planned_transaction{transaction_type::personal_development,0,0},
            planned_transaction{transaction_type::cards,0,0},
            planned_transaction{transaction_type::crap,0,0},
        };
        return expenses;
    }

    std::ostream& operator<< (std::ostream& os, const transaction& tr)
    {
        os << tr.id  << " | " << tr.m_date << " | " << tr.value << " | " << str_tran_type.at(tr.type) << " | " << tr.note;
        return os;
    }

    std::ostream& operator<< (std::ostream& os, const planned_transaction& ptr)
    {
        os << str_tran_type.at(ptr.type) << " | " << ptr.sum  << " | " << ptr.current;
        return os;
    }

    void monthly_budget::add_transaction(const transaction& new_transaction)
    {
        m_transactions.push_back(new_transaction);
        // todo update planned
        calculate_current_budget();
    }

    void monthly_budget::remove_transaction(int id)
    {
        std::remove_if(m_transactions.begin(),m_transactions.end(), [&id](const transaction& tr){
            return tr.id == id;
        });
        // todo update planned
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

        m_current_budget = m_initial_budget + transaction_sum;
    }
