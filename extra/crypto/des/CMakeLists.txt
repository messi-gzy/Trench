set(
        SOURCE_DES
        #${CMAKE_CURRENT_SOURCE_DIR}/src/encrypt.cpp
)
target_include_directories(
        trench_crypto
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(
        trench_crypto
        PUBLIC
        ${SOURCE_DES}
)