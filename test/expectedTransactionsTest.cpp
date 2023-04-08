#include <gtest/gtest.h>
#include <transaction/expected_transactions.hpp>

// TODO
class expectedTransactionsTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // empty one
        et1 = new transaction::expected_transactions();

        // filled_one
        std::map<transaction::expense_type, float> expenses{
            std::pair<transaction::expense_type, float>(transaction::expense_type::FOOD, 100)
        };

        std::map<transaction::income_type, float> incomes{
            std::pair<transaction::income_type, float>(transaction::income_type::SALARY, 100)
        };

        et2 = new transaction::expected_transactions(incomes, expenses);
    }

    void TearDown() override 
    {
        delete et1;
        delete et2;
    }

    transaction::expected_transactions* et1;
    transaction::expected_transactions* et2;
};

TEST_F(expectedTransactionsTest, construtor) 
{
    EXPECT_TRUE(et1->get_expected_expenses().empty());
    EXPECT_TRUE(et1->get_expected_incomes().empty());

    EXPECT_FALSE(et2->get_expected_expenses().empty());
    EXPECT_FALSE(et2->get_expected_incomes().empty());
}

TEST_F(expectedTransactionsTest, add_new_transaction_income) 
{
    EXPECT_TRUE(et1->get_expected_incomes().empty());
    EXPECT_TRUE(et1->add_new_transaction(transaction::income_type::INVESTMENTS, 100));
    EXPECT_FALSE(et1->get_expected_incomes().empty());

    EXPECT_TRUE(et2->add_new_transaction(transaction::income_type::OTHER, 100));
    EXPECT_FALSE(et2->add_new_transaction(transaction::income_type::OTHER, 100));
}

TEST_F(expectedTransactionsTest, add_new_transaction_expense) 
{
    EXPECT_TRUE(et1->get_expected_expenses().empty());
    EXPECT_TRUE(et1->add_new_transaction(transaction::expense_type::FOOD, 100));
    EXPECT_FALSE(et1->get_expected_expenses().empty());

    EXPECT_TRUE(et2->add_new_transaction(transaction::expense_type::OTHER, 100));
    EXPECT_FALSE(et2->add_new_transaction(transaction::expense_type::OTHER, 100));
}

TEST_F(expectedTransactionsTest, update_transaction_income) 
{
    EXPECT_FALSE(et1->update_transaction(transaction::income_type::SALARY, 100));
    EXPECT_TRUE(et1->add_new_transaction(transaction::income_type::SALARY, 100));
    EXPECT_TRUE(et1->update_transaction(transaction::income_type::SALARY, 200));
}

TEST_F(expectedTransactionsTest, update_transaction_expense) 
{
    EXPECT_FALSE(et1->update_transaction(transaction::expense_type::FOOD, 100));
    EXPECT_TRUE(et1->add_new_transaction(transaction::expense_type::FOOD, 100));
    EXPECT_TRUE(et1->update_transaction(transaction::expense_type::FOOD, 200));    
}

TEST_F(expectedTransactionsTest, get_expected_incomes) 
{
    std::map<transaction::income_type, float> incomes{
        std::pair<transaction::income_type, float>(transaction::income_type::SALARY, 100)
    };

    EXPECT_EQ(et2->get_expected_incomes(), incomes);
}

TEST_F(expectedTransactionsTest, get_expected_expenses) 
{
    std::map<transaction::expense_type, float> expenses{
        std::pair<transaction::expense_type, float>(transaction::expense_type::FOOD, 100)
    };

    EXPECT_EQ(et2->get_expected_expenses(), expenses);
}

TEST_F(expectedTransactionsTest, get_transaction_value_income) 
{
    EXPECT_FALSE(et1->get_transaction_value(transaction::income_type::INVESTMENTS).first);
    EXPECT_TRUE(et2->get_transaction_value(transaction::income_type::SALARY).first);
    EXPECT_EQ(et2->get_transaction_value(transaction::income_type::SALARY).second, 100);
}

TEST_F(expectedTransactionsTest, get_transaction_value_expense) 
{
    EXPECT_FALSE(et1->get_transaction_value(transaction::expense_type::FOOD).first);
    EXPECT_TRUE(et2->get_transaction_value(transaction::expense_type::FOOD).first);
    EXPECT_EQ(et2->get_transaction_value(transaction::expense_type::FOOD).second, 100);
}