set(HEADERS
    include/transaction/transaction.hpp
    include/transaction/expected_transactions.hpp
)

set(SOURCES
    src/transaction/transaction.cpp
    src/transaction/expected_transactions.cpp
)

set(EXE_SOURCES
    src/main.cpp
    ${SOURCES}
)

# inside test directory
set(TEST_SOURCES
    mainTest.cpp
    incomeTest.cpp
    expenseTest.cpp
    expectedTransactionsTest.cpp
)
