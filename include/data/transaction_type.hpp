#pragma once

#include <map>
#include <string>

enum class transaction_type: int 
{
    unknown = 0,

    // incomes
    salary,
    stocks,
    sales,
    other_incomes,

    // expenses
    bills,
    rent,
    insurances,
    subscriptions,
    food,
    transport,
    house_maintenance,
    social_outings,
    gym,
    clothes,
    appearance_health,
    furniture_equipment,
    personal_development,
    cards,
    crap
};

const std::map<transaction_type, std::string> str_tran_type
{
   {transaction_type::unknown, "unknown"},

   {transaction_type::salary, "salary"},
   {transaction_type::stocks, "stocks"},
   {transaction_type::sales, "sales"},
   {transaction_type::other_incomes, "other incomes"},

   {transaction_type::bills, "bills"},
   {transaction_type::rent, "rent"},
   {transaction_type::insurances, "insurances"},
   {transaction_type::subscriptions, "subscriptions"},
   {transaction_type::food, "food"},
   {transaction_type::transport, "transport"},
   {transaction_type::house_maintenance, "house and maintenance"},
   {transaction_type::social_outings, "socials"},
   {transaction_type::gym, "gym"},
   {transaction_type::clothes, "clothes"},
   {transaction_type::appearance_health, "appearance and health"},
   {transaction_type::furniture_equipment, "furniture and equipment"},
   {transaction_type::personal_development, "personal development"},
   {transaction_type::cards, "cards"},
   {transaction_type::crap, "crap"},   
};
