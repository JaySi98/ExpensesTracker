#include <gtest/gtest.h>
#include <transaction/transaction.hpp>

TEST(incomeTest, defaultConstructor) {
    transaction::income income {};

    EXPECT_EQ(income.id, 0);
    EXPECT_EQ(income.value, 0);
    EXPECT_EQ(income.note, "");
    EXPECT_EQ(income.day, gregorian::date{}); 
    EXPECT_EQ(income.type, std::shared_ptr<transaction::transaction_type>{});
}

TEST(incomeTest, constructor) {

    transaction::income_type type{0, "name"};
    transaction::income income {
        1,
        "text",
        gregorian::date(2000,gregorian::Feb,1),
        100,
        type
    };

    EXPECT_EQ(income.id, 1);
    EXPECT_EQ(income.value, 100);
    EXPECT_EQ(income.note, "text");
    EXPECT_EQ(income.day, gregorian::date(2000,gregorian::Feb,1)); 
    EXPECT_EQ(income.type->get_id(), 0);
    EXPECT_EQ(income.type->get_name(), "name");
}

// class incomeTest : public ::testing::Test
// {
// protected:

//     void SetUp() override
//     {

//     }

//     transaction::income income1{
//         "note 1",
//         gregorian::date(2001, gregorian::Feb,1),
//         100.0,
//         transaction::income_type::OTHER
//     };

//     transaction::income income2{
//         "note 2",
//         gregorian::date(2002, gregorian::Feb,1),
//         200.0,
//         transaction::income_type::OTHER
//     };
// };


// TEST_F(incomeTest, incomeUniqueID) {
//     EXPECT_TRUE(income1.get_id() != income2.get_id());
// }

// TEST_F(incomeTest, incomeGetNote) {
//     EXPECT_EQ(income1.get_note(), "note 1");
// }

// TEST_F(incomeTest, incomeGetValue) {
//     EXPECT_EQ(income1.get_value(), 100.0);  
// }

// TEST_F(incomeTest, incomeGetDay) {
//     EXPECT_EQ(income1.get_day(), gregorian::date(2001, gregorian::Feb,1));    
// }

// TEST_F(incomeTest, incomeGetType) {
//     EXPECT_EQ(income1.get_type(), transaction::income_type::OTHER);  
// }
