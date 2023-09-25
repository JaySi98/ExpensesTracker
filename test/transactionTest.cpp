#include <gtest/gtest.h>
#include <data/monthly_budget.hpp>
#include <string>

TEST(transactionTest, transaction_constructor)
{
    transaction tr1;
    EXPECT_EQ(tr1.id,       0);
    EXPECT_EQ(tr1.m_date,   day_clock::universal_day());
    EXPECT_EQ(tr1.category, transaction_category::unknown);
    EXPECT_EQ(tr1.note,     "");
    EXPECT_EQ(tr1.value,     0);

    transaction tr2{1, from_simple_string("2023-10-06"),transaction_category::salary, "note", 69};
    EXPECT_EQ(tr2.id,       1);
    EXPECT_EQ(tr2.m_date,   from_simple_string("2023-10-06"));
    EXPECT_EQ(tr2.category, transaction_category::salary);
    EXPECT_EQ(tr2.note,     "note");
    EXPECT_EQ(tr2.value,     69);
}

TEST(transactionTest, transaction_ostream)
{
    transaction tr1{1, from_simple_string("2023-09-06"),transaction_category::salary, "note", 69};
    std::stringstream buffer;
    buffer << tr1;

    std::string expected{"1 | 2023-Sep-06 | 69 | salary | note"};
    EXPECT_EQ(buffer.str(), expected);
}

TEST(transactionTest, planned_transaction_constructor)
{
    planned_transaction tr1;
    EXPECT_EQ(tr1.type,     transaction_type::expense);
    EXPECT_EQ(tr1.sum,      0);
    EXPECT_EQ(tr1.current,  0);

    planned_transaction tr2{transaction_type::income, 10, 11};
    EXPECT_EQ(tr2.type,     transaction_type::income);
    EXPECT_EQ(tr2.sum,      10);
    EXPECT_EQ(tr2.current,  11);
}

TEST(transactionTest, planned_transaction_ostream)
{
    planned_transaction tr1{transaction_type::income, 10, 11};
    std::stringstream buffer;
    buffer << tr1;

    std::string expected{"10 | 11"};
    EXPECT_EQ(buffer.str(), expected);
}
