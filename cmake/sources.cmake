set(HEADERS
    include/transaction.hpp
    include/transaction_type.hpp
    include/options_parser.hpp
)

set(SOURCES
    src/transaction.cpp
    src/options_parser.cpp
)

set(EXE_SOURCES
    src/main.cpp
    ${SOURCES}
)

# inside test directory
set(TEST_SOURCES
    mainTest.cpp
)
