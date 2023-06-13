set(
        SOURCE_SYSTEM
        ${CMAKE_CURRENT_SOURCE_DIR}/src/path.cpp
)
target_include_directories(
        trench_tools
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(
        trench_tools
        PUBLIC
        ${SOURCE_SYSTEM}
)
