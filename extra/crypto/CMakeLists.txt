set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS On)

add_library(
        TrenchCrypto
        SHARED
        ""
)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(rsa)
add_subdirectory(md5)
add_subdirectory(des)

