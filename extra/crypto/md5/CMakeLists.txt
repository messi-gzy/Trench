set(
        SOURCE_MD5
        ${CMAKE_CURRENT_SOURCE_DIR}/src/md5.cpp
)

target_include_directories(
        trench_crypto
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(
        trench_crypto
        PUBLIC
        ${SOURCE_MD5}
)
