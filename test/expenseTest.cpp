#include <gtest/gtest.h>
#include <expense/expense.hpp>

TEST(expense_test, expense_constructor_test)
{
    expense::expense epx(10, "note", gregorian::date(2023,gregorian::Feb,1));

    ASSERT_EQ(epx.get_date(), gregorian::date(2023,gregorian::Feb,1));
    ASSERT_EQ(epx.get_value(), 10);
    ASSERT_EQ(epx.get_info(), "note");

}