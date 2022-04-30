add_library(ark STATIC
    ark.c
    )

target_link_libraries(ark PRIVATE
    arknet
    )
