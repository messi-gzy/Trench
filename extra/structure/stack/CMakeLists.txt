set(
        SOURCE_STACK
        ${CMAKE_CURRENT_SOURCE_DIR}/src/structure.cpp
)
target_include_directories(
        TrenchStructure
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(
        TrenchStructure
        PUBLIC
        ${SOURCE_STACK}
)
