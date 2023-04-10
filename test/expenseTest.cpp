#include <gtest/gtest.h>
#include <transaction/transaction.hpp>

TEST(expenseTest, defaultConstructor) {
    transaction::expense expense {};

    EXPECT_EQ(expense.id, 0);
    EXPECT_EQ(expense.value, 0);
    EXPECT_EQ(expense.note, "");
    EXPECT_EQ(expense.day, gregorian::date{}); 
    EXPECT_EQ(expense.type, std::shared_ptr<transaction::expense_type>{});
}

TEST(expenseTest, constructor) {

    transaction::expense_type type{0, "name"};
    transaction::expense expense {
        1,
        "text",
        gregorian::date(2000,gregorian::Feb,1),
        100,
        type
    };

    EXPECT_EQ(expense.id, 1);
    EXPECT_EQ(expense.value, 100);
    EXPECT_EQ(expense.note, "text");
    EXPECT_EQ(expense.day, gregorian::date(2000,gregorian::Feb,1)); 
    EXPECT_EQ(expense.type->get_id(), 0);
    EXPECT_EQ(expense.type->get_name(), "name");
}

// class expenseTest : public ::testing::Test
// {
//     protected:

//         void SetUp() override
//         {

//         }

//         transaction::expense expense1{
//             "note 1",
//             gregorian::date(2001, gregorian::Feb,1),
//             100.0,
//             transaction::expense_type::OTHER
//         };

//         transaction::expense expense2{
//             "note 2",
//             gregorian::date(2002, gregorian::Feb,1),
//             200.0,
//             transaction::expense_type::OTHER
//         };
// };

// TEST_F(expenseTest, expenseUniqueID) {
//     EXPECT_TRUE(expense1.get_id() != expense2.get_id());
// }

// TEST_F(expenseTest, expenseGetNote) {
//     EXPECT_EQ(expense1.get_note(), "note 1");
// }

// TEST_F(expenseTest, expenseGetValue) {
//     EXPECT_EQ(expense1.get_value(), 100.0);  
// }

// TEST_F(expenseTest, expenseGetDay) {
//     EXPECT_EQ(expense1.get_day(), gregorian::date(2001, gregorian::Feb,1));   
// }

// TEST_F(expenseTest, expenseGetType) {
//     EXPECT_EQ(expense1.get_type(), transaction::expense_type::OTHER);  
// }