#include <gtest/gtest.h>
#include <data/monthly_budget.hpp>

TEST(monthlyBudgetTest, constructor)
{
    monthly_budget month;
    EXPECT_EQ(month.initial_budget, 0);
    EXPECT_EQ(month.current_budget, 0);
    EXPECT_EQ(month.m_date, day_clock::universal_day());
    EXPECT_TRUE(month.get_transactions().empty());
    EXPECT_EQ(month.planned.size(), 20);

    // one of each category
    std::vector<transaction_category> categories{
        transaction_category::unknown, transaction_category::salary, transaction_category::stocks,
        transaction_category::sales, transaction_category::other_incomes, transaction_category::bills,
        transaction_category::rent, transaction_category::insurances, transaction_category::subscriptions,
        transaction_category::food, transaction_category::transport, transaction_category::house_maintenance,
        transaction_category::social_outings, transaction_category::gym, transaction_category::clothes,
        transaction_category::appearance_health, transaction_category::furniture_equipment, transaction_category::personal_development,
        transaction_category::cards, transaction_category::crap,
    };

    for(auto cat : categories)
    {
        EXPECT_EQ(month.planned.count(cat), 1);
    }
}

TEST(monthlyBudgetTest, add_transaction)
{
    monthly_budget month;
    transaction tr1{1, day_clock::universal_day(),transaction_category::salary, "note", 69};
    month.add_transaction(tr1);
    EXPECT_EQ(month.get_transactions().size(), 1);
    EXPECT_EQ(month.current_budget, 69);
    EXPECT_EQ(month.planned[transaction_category::salary].current, 69);

    month.add_transaction(tr1);
    EXPECT_EQ(month.get_transactions().size(), 1);
    EXPECT_EQ(month.current_budget, 69);
    EXPECT_EQ(month.planned[transaction_category::salary].current, 69);

    transaction tr2{2, day_clock::universal_day(),transaction_category::bills, "note", -50};
    month.add_transaction(tr2);
    EXPECT_EQ(month.get_transactions().size(), 2);
    EXPECT_EQ(month.current_budget, 19);
    EXPECT_EQ(month.planned[transaction_category::bills].current, -50);

    // check planned
}

TEST(monthlyBudgetTest, remove_transaction)
{
    monthly_budget month;
    transaction tr1{1, day_clock::universal_day(),transaction_category::salary, "note", 69};
    month.add_transaction(tr1);

    month.remove_transaction(tr1.id);
    EXPECT_EQ(month.get_transactions().size(), 0);
    EXPECT_EQ(month.current_budget, 0);
    EXPECT_EQ(month.planned[transaction_category::bills].current, 0);
}