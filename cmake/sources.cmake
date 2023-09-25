set(HEADERS
    include/data/transaction_type.hpp
    include/data/monthly_budget.hpp
    include/data/options_parser.hpp
)

set(SOURCES
    src/data/options_parser.cpp
    src/data/monthly_budget.cpp
)

set(EXE_SOURCES
    src/main.cpp
    ${SOURCES}
)

# inside test directory
set(TEST_SOURCES
    mainTest.cpp

    monthlyBudgetTest.cpp
    transactionTest.cpp
    optionParserTest.cpp
)
