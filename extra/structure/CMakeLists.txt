add_library(
        trench_structure
        STATIC
        ""
)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(stack)
add_subdirectory(vector)
add_subdirectory(memory_pool)