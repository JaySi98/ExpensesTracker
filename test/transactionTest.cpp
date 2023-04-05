#include <gtest/gtest.h>
#include <transaction/transaction.hpp>

TEST(transaction_test, transaction_constructor_test)
{
    transaction::transaction transaction(10, "note", gregorian::date(2023,gregorian::Feb,1));

    ASSERT_EQ(transaction.get_day(), gregorian::date(2023,gregorian::Feb,1));
    ASSERT_EQ(transaction.get_value(), 10);
    ASSERT_EQ(transaction.get_info(), "note");

}