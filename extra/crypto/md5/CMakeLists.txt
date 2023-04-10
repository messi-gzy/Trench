include_directories(
        ./include
)

set(
        SOURCE_MD5
        ./src/md5.cpp
)

add_library(
        md5
        STATIC
        ${SOURCE_MD5}
)
