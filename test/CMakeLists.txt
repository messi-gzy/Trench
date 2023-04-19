include_directories(
        ${PROJECT_SOURCE_DIR}/libs/jsoncpp/include
        ${PROJECT_SOURCE_DIR}/extra/crypto/md5/include
        ${PROJECT_SOURCE_DIR}/extra/crypto/rsa/include
	  ${PROJECT_SOURCE_DIR}/extra/crypto/des/include
)

link_directories(
        ${CMAKE_BINARY_DIR}/bin
)
# test_md5
add_executable(
        test_md5
        extra/crypto/test_md5.cpp
)

# test_rsa
add_executable(
        test_rsa
        extra/crypto/test_rsa.cpp
)

# test_des
add_executable(
        test_des
        extra/crypto/test_des.cpp
)

## out_path
IF (WIN32)
    target_link_libraries(
            test_md5
            trench_crypto.dll
    )
    set_target_properties(
            test_md5
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )
    target_link_libraries(
            test_rsa
            trench_crypto.dll
    )
    set_target_properties(
            test_rsa
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )
    target_link_libraries(
            test_des
            trench_crypto.dll
    )
    set_target_properties(
            test_des
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )
ELSEIF (APPLE)
    target_link_libraries(
            test_md5
            trench_crypto.so
    )
    set_target_properties(
            test_md5
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test
    )
    target_link_libraries(
            test_rsa
            trench_crypto.so
    )
    set_target_properties(
            test_rsa
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test
    )
    target_link_libraries(
            test_des
            trench_crypto.dll
    )
    set_target_properties(
            test_des
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test
    )
ELSEIF (UNIX)
    target_link_libraries(
            test_md5
            trench_crypto.so
    )
    set_target_properties(
            test_md5
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test
    )
    target_link_libraries(
            test_rsa
            trench_crypto.so
    )
    set_target_properties(
            test_rsa
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test
    )
    target_link_libraries(
            test_des
            trench_crypto.dll
    )
    set_target_properties(
            test_des
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test
    )
ENDIF ()
