include_directories(
        ./include
)

set(
        SOURCE_SPDLOG
        ./test.cpp
)

add_library(
        spdlog
        SHARED
        ${SOURCE_SPDLOG}
)