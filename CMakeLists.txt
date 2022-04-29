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

# ark lib
add_library(ark STATIC
    src/ark/ark.c
    )

target_include_directories(ark PRIVATE
    ${PROJECT_SOURCE_DIR}/src
    )

# Runtime
add_executable(arkrt
    src/main.c
    )

target_link_libraries(arkrt PRIVATE
    ark
    )
