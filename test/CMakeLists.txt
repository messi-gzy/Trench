include_directories(
        ${PROJECT_SOURCE_DIR}/libs/jsoncpp/include
        ${PROJECT_SOURCE_DIR}/extra/crypto/md5/include
        ${PROJECT_SOURCE_DIR}/extra/crypto/rsa/include
	    ${PROJECT_SOURCE_DIR}/extra/crypto/des/include
)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# test_rsa
add_executable(
        test_crypto
        extra/crypto/test_crypto.cpp
)

# out_path
IF (WIN32)
    target_link_libraries(
            test_crypto
            TrenchCrypto.dll
    )
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


