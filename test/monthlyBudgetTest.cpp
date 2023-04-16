#include <gtest/gtest.h>
#include <budget/monthly_budget.hpp>

class monthlyBudgetTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // transaction::transaction_type type1 = {1, "TYPE 1"};
        // transaction::transaction_type type2 = {2, "TYPE 2"};
        // transaction::transaction_type type3 = {3, "TYPE 3"};

        // transaction::transaction transaction1 = {1, "trans1", gregorian::date(2000,gregorian::Feb,1), 100, type1};
        // transaction::transaction transaction2 = {2, "trans2", gregorian::date(2000,gregorian::Feb,2), 200, type2};
        // transaction::transaction transaction3 = {3, "trans3", gregorian::date(2000,gregorian::Feb,3), 300, type3};

        // st.add_new_transaction(transaction1);
        // st.add_new_transaction(transaction2);
        // st.add_new_transaction(transaction3);


    }

    void TearDown() override 
    { 

    }

    budget::monthly_budget month;
};

TEST_F(monthlyBudgetTest, constructor)
{

}

TEST_F(monthlyBudgetTest, add_transaction)
{
    
}

TEST_F(monthlyBudgetTest, current_budget)
{
    
}