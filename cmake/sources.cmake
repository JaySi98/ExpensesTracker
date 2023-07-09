set(HEADERS
    include/transaction.hpp
    include/date.hpp
)

set(SOURCES
    src/transaction.cpp
    src/date.cpp
)

set(EXE_SOURCES
    src/main.cpp
    ${SOURCES}
)

# inside test directory
set(TEST_SOURCES
    mainTest.cpp
)
