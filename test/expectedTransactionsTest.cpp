#include <gtest/gtest.h>
#include <transaction/expected_transactions.hpp>

// TODO
class expectedTransactionsTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        et1 = new transaction::expected_transactions();
        et2 = new transaction::expected_transactions();
    }

    void TearDown() override 
    {
        delete et1;
        delete et2;
    }

    transaction::expected_transactions* et1;
    transaction::expected_transactions* et2;
};