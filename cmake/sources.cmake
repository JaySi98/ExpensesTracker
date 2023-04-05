set(HEADERS
    include/transaction/transaction.hpp
)

set(SOURCES
    src/transaction/transaction.cpp
)

set(EXE_SOURCES
    src/main.cpp
    ${SOURCES}
)

# inside test directory
set(TEST_SOURCES
    mainTest.cpp
    transactionTest.cpp
)
