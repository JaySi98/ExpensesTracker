set(HEADERS
    include/data/transaction_type.hpp
    include/data/monthly_budget.hpp
    include/data/options_parser.hpp

    # include/view_models/base_vm.hpp
    # include/view_models/main_vm.hpp
    # include/view_models/reports_vm.hpp
    # include/domain_models/base_dm.hpp
    # include/domain_models/main_dm.hpp
    # include/domain_models/reports_dm.hpp
)

set(SOURCES
    src/data/options_parser.cpp
    src/data/monthly_budget.cpp

    # src/view_models/main_vm.cpp
    # src/view_models/reports_vm.cpp
    # src/domain_models/main_dm.cpp
    # src/domain_models/reports_dm.cpp
)

set(EXE_SOURCES
    src/main.cpp
    ${SOURCES}
)

# inside test directory
set(TEST_SOURCES
    mainTest.cpp
)
