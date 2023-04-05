set(HEADERS
    include/expense/expense.hpp
)

set(SOURCES
    src/expense/expense.cpp
)

set(EXE_SOURCES
    src/main.cpp
    ${SOURCES}
)

# inside test directory
set(TEST_SOURCES
    mainTest.cpp
    expenseTest.cpp
)
