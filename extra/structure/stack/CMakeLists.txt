set(
        SOURCE_STACK
        ${CMAKE_CURRENT_SOURCE_DIR}/src/structure.cpp
)
target_include_directories(
        trench_structure
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(
        trench_structure
        PUBLIC
        ${SOURCE_STACK}
)
