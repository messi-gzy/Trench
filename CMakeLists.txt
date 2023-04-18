cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
# ���ñ�����
IF (WIN32)
    message("windows")
    SET(SYSTEM_NAME windows)
    SET(CMAKE_C_COMPILER gcc)
    SET(CMAKE_CXX_COMPILER g++)
ELSEIF (APPLE)
    message("apple")
    SET(SYSTEM_NAME apple)
    SET(CMAKE_C_COMPILER clang)
    SET(CMAKE_CXX_COMPILER clang++)
ELSEIF (UNIX)
    message("unix")
    SET(SYSTEM_NAME unix)
    SET(CMAKE_C_COMPILER gcc)
    SET(CMAKE_CXX_COMPILER g++)
ENDIF ()

PROJECT(Trench LANGUAGES CXX)

IF (CMAKE_CXX_COMPILER_LOADED)
    message(STATUS "The C++ compiler is: ${CMAKE_CXX_COMPILER}")
    message(STATUS "The C++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}")
    message(STATUS "Is the C++ from GNU? ${CMAKE_COMPILER_IS_GNUCXX}")
    message(STATUS "The C++ compiler version is: ${CMAKE_CXX_COMPILER_VERSION}")
ENDIF ()

## �������·��
SET(
        CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/bin
)
SET(
        CMAKE_ARCHIVE_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/lib
)


# ���ͷ�ļ�Ŀ¼
#include_directories(
#        ${PROJECT_SOURCE_DIR}/libs/spdlog/include
#        ${PROJECT_SOURCE_DIR}/libs/jsoncpp/include
#)

# �����Ŀ¼
add_subdirectory(libs)
add_subdirectory(extra)
add_subdirectory(src)
add_subdirectory(test)

add_dependencies(test_md5 trench_crypto)
add_dependencies(test_rsa trench_crypto)
#ͷ�ļ�
file(
        COPY
        ${PROJECT_SOURCE_DIR}/include
        DESTINATION
        ${PROJECT_BINARY_DIR}
)
#�����ļ�
file(
        COPY
        ${PROJECT_SOURCE_DIR}/conf
        DESTINATION
        ${PROJECT_BINARY_DIR}
)
#�ĵ�˵��
file(
        COPY
        ${PROJECT_SOURCE_DIR}/docs
        DESTINATION
        ${PROJECT_BINARY_DIR}
)
