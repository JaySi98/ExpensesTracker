#include <gtest/gtest.h>
#include <transaction/saved_transactions.hpp>

class savedTransactionsTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        transaction::transaction_type type1 = {1, "TYPE 1"};
        transaction::transaction_type type2 = {2, "TYPE 2"};
        transaction::transaction_type type3 = {3, "TYPE 3"};

        transaction::transaction transaction1 = {1, "trans1", gregorian::date(2000,gregorian::Feb,1), 100, type1};
        transaction::transaction transaction2 = {2, "trans2", gregorian::date(2000,gregorian::Feb,2), 200, type2};
        transaction::transaction transaction3 = {3, "trans3", gregorian::date(2000,gregorian::Feb,3), 300, type3};

        st.add_new_transaction(transaction1);
        st.add_new_transaction(transaction2);
        st.add_new_transaction(transaction3);
    }

    // void TearDown() override 
    // { }

    transaction::saved_transactions st;
};

TEST_F(savedTransactionsTest, remove_transaction)
{
    st.remove_transaction(1);
    EXPECT_EQ(st.get_transactions().size(), 2);
}

TEST_F(savedTransactionsTest, get_transactions)
{
    EXPECT_EQ(st.get_transactions().size(), 3);

    transaction::transaction_type type1 = {1, "TYPE 1"};
    transaction::transaction transaction1 = {1, "trans1", gregorian::date(2000,gregorian::Feb,1), 100, type1};

    EXPECT_EQ(st.get_transactions().front(), transaction1);
}

TEST_F(savedTransactionsTest, get_sum_by_type)
{
    transaction::transaction_type type1 = {1, "TYPE 1"};
    transaction::transaction_type type2 = {2, "TYPE 2"};
    transaction::transaction_type type3 = {3, "TYPE 3"};

    transaction::transaction transaction1 = {1, "trans1", gregorian::date(2000,gregorian::Feb,1), 100, type1};
    transaction::transaction transaction2 = {2, "trans2", gregorian::date(2000,gregorian::Feb,2), 200, type2};
    transaction::transaction transaction3 = {3, "trans3", gregorian::date(2000,gregorian::Feb,3), 300, type3};

    transaction::transaction_type new_type{3, "TYPE 3"};
    transaction::transaction new_transaction{1, "trans1", gregorian::date(2000,gregorian::Feb,1), 100, new_type};
    st.add_new_transaction(new_transaction);
    st.add_new_transaction(new_transaction);

    auto expenses = st.get_sum_by_type();
    EXPECT_EQ(expenses.size(), 3) << "failed size";

    EXPECT_EQ(expenses[new_type], 500) << "failed new type";
    EXPECT_EQ(expenses[type1], 100) << "failed type 1";
    EXPECT_EQ(expenses[type2], 200) << "failed type 2";;
    EXPECT_EQ(expenses[type3], 500) << "failed type 3";;
}

TEST_F(savedTransactionsTest, get_sum)
{
    EXPECT_EQ(st.get_sum(), 600);

    transaction::transaction_type new_type{3, "TYPE 3"};
    transaction::transaction new_transaction{1, "trans1", gregorian::date(2000,gregorian::Feb,1), 100, new_type};
    st.add_new_transaction(new_transaction);

    EXPECT_EQ(st.get_sum(), 700);

}