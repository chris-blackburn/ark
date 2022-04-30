# Headers from other components
include_directories(${PROJECT_SOURCE_DIR}/src)

# To encourage modularity, ark and its components are built as libraries.
add_subdirectory(net)
add_subdirectory(ark)

# Runtime
add_executable(arkrt
    main.c
    )

target_link_libraries(arkrt PRIVATE
    ark
    )
