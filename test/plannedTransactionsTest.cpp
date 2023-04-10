#include <gtest/gtest.h>
#include <transaction/planned_transactions.hpp>

class plannedTransactionsTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        transaction::income_type ex1{0, "a"};
        transaction::income_type ex2{1, "b"};
        transaction::income_type ex3{2, "c"};
        planned_expenses = new transaction::planned_transactions();
        planned_expenses->add_new_transaction(ex1, 100);
        planned_expenses->add_new_transaction(ex2, 200);
        planned_expenses->add_new_transaction(ex3, 300);
    }

    void TearDown() override 
    {
        delete planned_expenses;
    }

    transaction::planned_transactions* planned_expenses;
};


TEST_F(plannedTransactionsTest, add_new_transaction) 
{
    transaction::income_type old{0, "a"};
    transaction::income_type unique{5, "unique"};

    EXPECT_FALSE(planned_expenses->add_new_transaction(old, 100));
    EXPECT_TRUE(planned_expenses->add_new_transaction(unique, 100));
}

TEST_F(plannedTransactionsTest, update_transaction) 
{
    transaction::income_type old{0, "a"};
    transaction::income_type unique{5, "unique"};

    EXPECT_TRUE(planned_expenses->update_transaction(old, 100));
    EXPECT_FALSE(planned_expenses->update_transaction(unique, 100));
}

TEST_F(plannedTransactionsTest, get_transaction) 
{
    transaction::income_type ex1{0, "a"};
    std::pair<transaction::transaction_type, float> result = planned_expenses->get_transaction(ex1);
    EXPECT_EQ(result.second, 100);

    transaction::income_type incorrect{10, "a"};
    EXPECT_THROW(planned_expenses->get_transaction(incorrect), std::logic_error);
}

TEST_F(plannedTransactionsTest, get_sum) 
{
    EXPECT_EQ(planned_expenses->get_sum(), 600);
}
