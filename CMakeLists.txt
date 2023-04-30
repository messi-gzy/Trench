cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
# compiler
IF (WIN32)
	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
#     message("windows")
#     SET(SYSTEM_NAME windows)
    SET(CMAKE_C_COMPILER gcc)
    SET(CMAKE_CXX_COMPILER g++)
ELSEIF (APPLE)
#     message("apple")
#     SET(SYSTEM_NAME apple)
#     SET(CMAKE_C_COMPILER clang)
#     SET(CMAKE_CXX_COMPILER clang++)
ELSEIF (UNIX)
#     message("unix")
#     SET(SYSTEM_NAME unix)
#     SET(CMAKE_C_COMPILER gcc)
#     SET(CMAKE_CXX_COMPILER g++)
ENDIF ()

PROJECT(Trench LANGUAGES CXX)


set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

IF (CMAKE_CXX_COMPILER_LOADED)
    message(STATUS "The C++ compiler is: ${CMAKE_CXX_COMPILER}")
    message(STATUS "The C++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}")
    message(STATUS "Is the C++ from GNU? ${CMAKE_COMPILER_IS_GNUCXX}")
    message(STATUS "The C++ compiler version is: ${CMAKE_CXX_COMPILER_VERSION}")
ENDIF ()

# .lib|.a
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# .so|.dll
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# .exe|.out
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})


# subdirectory
add_subdirectory(libs)
add_subdirectory(extra)
add_subdirectory(src)

# Specifies the library generation order

add_dependencies(test_crypto TrenchCrypto)
add_dependencies(TrenchCrypto TrenchJson)


# copy include
file(
        COPY
        ${PROJECT_SOURCE_DIR}/include
        DESTINATION
        ${PROJECT_BINARY_DIR}
)
# copy conf
file(
        COPY
        ${PROJECT_SOURCE_DIR}/conf
        DESTINATION
        ${PROJECT_BINARY_DIR}
)
# copy docs
file(
        COPY
        ${PROJECT_SOURCE_DIR}/docs
        DESTINATION
        ${PROJECT_BINARY_DIR}
)
