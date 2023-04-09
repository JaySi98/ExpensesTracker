#include <gtest/gtest.h>
#include <transaction/transaction_type.hpp>

TEST(transactionTypeTest, get_id) {
    transaction::income_type income_t(0, "test");
    EXPECT_EQ(income_t.get_id(), 0);

    transaction::expense_type expense_t(0, "test");
    EXPECT_EQ(expense_t.get_id(), 0);   
}

TEST(transactionTypeTest, get_name) {
    transaction::income_type income_t(0, "test");
    EXPECT_EQ(income_t.get_name(), "test");   

    transaction::expense_type expense_t(0, "test");
    EXPECT_EQ(expense_t.get_name(), "test");   
}