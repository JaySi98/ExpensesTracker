#include <gtest/gtest.h>
#include <transaction/transaction.hpp>


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