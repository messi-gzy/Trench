add_library(
        TrenchStructure
        STATIC
        ""
)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(stack)
add_subdirectory(vector)