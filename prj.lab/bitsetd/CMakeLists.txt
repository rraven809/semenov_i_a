add_library(bitsetd bitsetd.h bitsetd.cpp)

add_executable(bitsetd_test bitsetd_test.cpp)
target_link_libraries(bitsetd_test bitsetd)