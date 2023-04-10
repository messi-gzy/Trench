include_directories(
        ${PROJECT_SOURCE_DIR}/lib/jsoncpp/include
)


add_executable(
        test_cpp
        ./test_cpp.cpp
)

target_link_libraries(
        test_cpp
        json
)