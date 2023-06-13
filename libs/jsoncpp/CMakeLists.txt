include_directories(
        ./include
)

add_library(
        trench_json
        STATIC
        ./src/json_reader.cpp
        ./src/json_value.cpp
        ./src/json_valueiterator.inl
        ./src/json_writer.cpp
)

#add_executable(
#        test
#        ./test/test.cpp
#)
#target_link_libraries(
#        test
#        json
#)