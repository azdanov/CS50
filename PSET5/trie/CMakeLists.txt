add_library(dictionary_trie dictionary.c)
add_executable(speller_trie speller.c)
target_link_libraries(speller_trie cs50 dictionary_old)
