set(HEADERS
    include/data/transaction_type.hpp
    include/data/monthly_budget.hpp

    include/functional/options_parser.hpp
    include/functional/options_controller.hpp
)

set(SOURCES
    src/data/monthly_budget.cpp

    src/functional/options_parser.cpp
    src/functional/options_controller.cpp
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
