set(
        SOURCE_MD5
        ${CMAKE_CURRENT_SOURCE_DIR}/src/md5.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/crypto.cpp
)

target_include_directories(
        TrenchCrypto
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(
        TrenchCrypto
        PUBLIC
        ${SOURCE_MD5}
)
