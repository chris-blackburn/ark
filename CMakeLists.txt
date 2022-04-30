cmake_minimum_required(VERSION 3.4)
project(ark LANGUAGES C)

set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra -Werror -pedantic
    "$<$<CONFIG:DEBUG>:-g;-O0>"
    "$<$<CONFIG:RELEASE>:-O3>"
    )

# Public includes
include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
