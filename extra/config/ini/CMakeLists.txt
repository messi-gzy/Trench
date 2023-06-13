set(
        SOURCE_INI
        ${CMAKE_CURRENT_SOURCE_DIR}/src/IniConfig.cpp
)

target_include_directories(
        trench_config
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(
        trench_config
        PUBLIC
        ${SOURCE_INI}
)