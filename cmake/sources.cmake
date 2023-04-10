set(HEADERS
    include/transaction/transaction.hpp
    include/transaction/transaction_type.hpp
    include/transaction/planned_transactions.hpp
    # include/transaction/saved_transactions.hpp
    # include/budget/monthly_budget.hpp
)

set(SOURCES
    src/transaction/transaction_type.cpp
    src/transaction/planned_transactions.cpp
    # src/transaction/saved_transactions.cpp
    # src/budget/monthly_budget.cpp
)

set(EXE_SOURCES
    src/main.cpp
    ${SOURCES}
)

# inside test directory
set(TEST_SOURCES
    mainTest.cpp
    transactionTypeTest.cpp
    incomeTest.cpp
    expenseTest.cpp
    plannedTransactionsTest.cpp
    # savedTransactionsTest.cpp
)
