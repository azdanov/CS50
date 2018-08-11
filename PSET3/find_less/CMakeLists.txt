add_library(helpers_less helpers.c)
add_executable(find_less find.c)
target_link_libraries(find_less cs50 helpers_less)
