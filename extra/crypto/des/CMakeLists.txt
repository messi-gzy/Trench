set(
        SOURCE_DES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/secret_key.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/iterate_encrypt.cpp
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
        ${SOURCE_DES}
)

