add_library(dictionary_old dictionary.c)
add_executable(speller_old speller.c)
target_link_libraries(speller_old cs50 dictionary_old)
