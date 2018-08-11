add_library(helpers_more helpers.c)
add_executable(find_more find.c)
target_link_libraries(find_more cs50 helpers_more)
