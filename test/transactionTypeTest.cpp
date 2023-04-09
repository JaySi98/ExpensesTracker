#include <gtest/gtest.h>
#include <transaction/transaction_type.hpp>

int id_generator(void)
{
    static int count = 0;
    return ++count;
}

TEST(transactionTypeTest, get_id) {
    transaction::income_type income_t(&id_generator, "test");
    EXPECT_EQ(income_t.get_id(), 1);

    transaction::expense_type expense_t(&id_generator, "test");
    EXPECT_EQ(expense_t.get_id(), 2);   
}

TEST(transactionTypeTest, get_name) {
    transaction::income_type income_t(&id_generator, "test");
    EXPECT_EQ(income_t.get_name(), "test");   

    transaction::expense_type expense_t(&id_generator, "test");
    EXPECT_EQ(expense_t.get_name(), "test");   
}