#include <gtest/gtest.h>
#include <transaction/planned_transactions.hpp>

class plannedTransactionsTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // et1 = new transaction::planned_transactions();
    }

    void TearDown() override 
    {
        // delete et1;
    }

    transaction::planned_transactions* et1;
};


TEST_F(plannedTransactionsTest, add_new_transaction) 
{

}

TEST_F(plannedTransactionsTest, update_transaction) 
{

}

TEST_F(plannedTransactionsTest, get_sum) 
{

}
