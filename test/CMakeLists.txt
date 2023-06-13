include_directories(
        ${PROJECT_SOURCE_DIR}/libs/jsoncpp/include
        ${PROJECT_SOURCE_DIR}/libs/googletest/include
        ${PROJECT_SOURCE_DIR}/extra/crypto/md5/include
        ${PROJECT_SOURCE_DIR}/extra/crypto/rsa/include
        ${PROJECT_SOURCE_DIR}/extra/crypto/des/include
        ${PROJECT_SOURCE_DIR}/extra/config/ini/include
        ${PROJECT_SOURCE_DIR}/include
)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

IF (WIN32)
    set(
            TEST_CRYPTO_SOURCE
            extra/test_crypto.cpp
            ${PROJECT_SOURCE_DIR}/assets/app.rc
    )
    set(
            TEST_CONFIG_SOURCE
            extra/test_config.cpp
            ${PROJECT_SOURCE_DIR}/assets/app.rc
    )
ELSE ()
    set(
            TEST_CRYPTO_SOURCE
            extra/test_crypto.cpp
    )
    set(
            TEST_CONFIG_SOURCE
            extra/test_config.cpp
    )
ENDIF ()


# test_rsa
add_executable(
        test_crypto
        ${TEST_CRYPTO_SOURCE}
)

add_executable(
        test_config
        ${TEST_CONFIG_SOURCE}
)

#target_link_libraries(
#        test_crypto
#        gtest
#)

# out_path
IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    IF (MSVC)
        target_link_libraries(
                test_crypto
                trench_crypto
        )
        target_link_libraries(
                test_config
                trench_config
        )
    ELSE ()
        target_link_libraries(
                test_crypto
                PUBLIC
                trench_crypto.dll
        )
        target_link_libraries(
                test_config
                PUBLIC
                trench_config.dll
        )
    ENDIF ()

    set_target_properties(
            test_crypto
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )

    set_target_properties(
            test_config
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )
ELSE ()
    target_link_libraries(
            test_crypto
            trench_crypto
    )
    target_link_libraries(
            test_config
            trench_config
    )
    set_target_properties(
            test_crypto
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test
    )
    set_target_properties(
            test_config
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test
    )

ENDIF ()


