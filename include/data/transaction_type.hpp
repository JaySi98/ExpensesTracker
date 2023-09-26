#pragma once

#include <map>
#include <string>

enum class options: int
{
    help = 0,
    types,
    add,
    month,
    date,
    category,
    note,
    value,
};

enum class transaction_type: int
{
    income = 0,
    expense
};

enum class transaction_category: int 
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

const static std::map<transaction_category, std::string> str_tran_cat
{
   {transaction_category::unknown,              "unknown"},

   {transaction_category::salary,               "salary"},
   {transaction_category::stocks,               "stocks"},
   {transaction_category::sales,                "sales"},
   {transaction_category::other_incomes,        "other incomes"},

   {transaction_category::bills,                "bills"},
   {transaction_category::rent,                 "rent"},
   {transaction_category::insurances,           "insurances"},
   {transaction_category::subscriptions,        "subscriptions"},
   {transaction_category::food,                 "food"},
   {transaction_category::transport,            "transport"},
   {transaction_category::house_maintenance,    "house and maintenance"},
   {transaction_category::social_outings,       "socials"},
   {transaction_category::gym,                  "gym"},
   {transaction_category::clothes,              "clothes"},
   {transaction_category::appearance_health,    "appearance and health"},
   {transaction_category::furniture_equipment,  "furniture and equipment"},
   {transaction_category::personal_development, "personal development"},
   {transaction_category::cards,                "cards"},
   {transaction_category::crap,                 "crap"},   
};

static std::map<options, std::string> str_options
{
    {options::help,     "help"},
    {options::types,    "types"},
    {options::add,      "add"},
    {options::month,    "month"},
    {options::date,     "date"},
    {options::category, "cat"},
    {options::note,     "note"},
    {options::value,    "value"},
};
