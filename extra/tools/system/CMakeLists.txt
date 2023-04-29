set(
        SOURCE_SYSTEM
        ${CMAKE_CURRENT_SOURCE_DIR}/src/path.cpp
)
target_include_directories(
        TrenchTools
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(
        TrenchTools
        PUBLIC
        ${SOURCE_SYSTEM}
)
