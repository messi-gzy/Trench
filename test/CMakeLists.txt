include_directories(
        ${PROJECT_SOURCE_DIR}/libs/jsoncpp/include
        ${PROJECT_SOURCE_DIR}/libs/googletest/include
        ${PROJECT_SOURCE_DIR}/extra/crypto/md5/include
        ${PROJECT_SOURCE_DIR}/extra/crypto/rsa/include
        ${PROJECT_SOURCE_DIR}/extra/crypto/des/include
        ${PROJECT_SOURCE_DIR}/include
)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

IF (WIN32)
    set(
            TEST_CRYPTO_SOURCE
            extra/crypto/test_crypto.cpp
            ${PROJECT_SOURCE_DIR}/assets/app.rc
    )
ELSEIF ()
    set(
            TEST_CRYPTO_SOURCE
            extra/crypto/test_crypto.cpp
    )
ENDIF ()


# test_rsa
add_executable(
        test_crypto
        ${TEST_CRYPTO_SOURCE}
)

target_link_libraries(
        test_crypto
        gtest
)

# out_path
IF (WIN32)
    IF (MSVC)
        target_link_libraries(
                test_crypto
                TrenchCrypto
        )
    ELSEIF ()
        target_link_libraries(
                test_crypto
                TrenchCrypto.dll
        )
    ENDIF ()
    set_target_properties(
            test_crypto
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )
ELSEIF (APPLE)
    target_link_libraries(
            test_crypto
            TrenchCrypto.so
    )
    set_target_properties(
            test_crypto
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test
    )
ELSEIF (UNIX)
    target_link_libraries(
            test_crypto
            TrenchCrypto.so
    )
    set_target_properties(
            test_crypto
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test
    )
ENDIF ()


