set(HEADERS
    include/transaction.hpp
    include/transaction_type.hpp
)

set(SOURCES
    src/transaction.cpp
)

set(EXE_SOURCES
    src/main.cpp
    ${SOURCES}
)

# inside test directory
set(TEST_SOURCES
    mainTest.cpp
)
