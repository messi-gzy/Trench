cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
# 设置编译器
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

## 设置输出路径
SET(
        CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/bin
)
SET(
        CMAKE_ARCHIVE_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/lib
)


# 添加头文件目录
#include_directories(
#        ${PROJECT_SOURCE_DIR}/libs/spdlog/include
#        ${PROJECT_SOURCE_DIR}/libs/jsoncpp/include
#)

# 添加子目录
add_subdirectory(libs)
add_subdirectory(extra)
add_subdirectory(src)
add_subdirectory(test)
#头文件
file(
        COPY
        ${PROJECT_SOURCE_DIR}/include
        DESTINATION
        ${PROJECT_BINARY_DIR}
)
#配置文件
file(
        COPY
        ${PROJECT_SOURCE_DIR}/conf
        DESTINATION
        ${PROJECT_BINARY_DIR}
)
#文档说明
file(
        COPY
        ${PROJECT_SOURCE_DIR}/docs
        DESTINATION
        ${PROJECT_BINARY_DIR}
)
