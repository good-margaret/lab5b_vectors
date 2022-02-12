add_library(data_structures
        vector/vector.c
        voidVector/voidVector.c
        matrix/matrix.c)

target_link_libraries(data_structures algorithms)