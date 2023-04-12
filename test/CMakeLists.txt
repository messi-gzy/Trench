include_directories(
        ${PROJECT_SOURCE_DIR}/libs/jsoncpp/include
        ${PROJECT_SOURCE_DIR}/extra/crypto/md5/include
        ${PROJECT_SOURCE_DIR}/extra/crypto/rsa/include
)

link_directories(
        ${CMAKE_BINARY_DIR}/bin
)

add_executable(
        test_cpp
        test_cpp.cpp
)

target_link_libraries(
        test_cpp
        trench_crypto.dll
)

## …Ë÷√ ‰≥ˆ¬∑æ∂
IF (WIN32)
    set_target_properties(
        test_cpp
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
ELSEIF (APPLE)
    set_target_properties(
        test_cpp
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test
)
ELSEIF (UNIX)
    set_target_properties(
        test_cpp
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test
)
ENDIF ()
