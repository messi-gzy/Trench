set(
        SOURCE_RSA
        ${CMAKE_CURRENT_SOURCE_DIR}/src/encrypt.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/key_pair.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/decode.cpp
)
target_include_directories(
        trench_crypto
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(
        trench_crypto
        PUBLIC
        ${SOURCE_RSA}
)