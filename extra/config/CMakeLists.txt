set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(
        trench_config
        SHARED
        ""
)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(ini)