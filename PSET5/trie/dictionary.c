/**
 * Implements a dictionary's functionality.
 */

#include "dictionary.h"

// Global trie root as dictionary
Node *root;
unsigned word_count = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    Node *curr = root;
    bool status = false;

    for (int j = 0, word_len = (int) strlen(word); j < word_len; ++j) {
        int position = tolower(word[j]) - 'a';

        // Add apostrophe
        if (position == -58) {
            position = 26;
        }

        if (curr->children[position]) {
            if (j == word_len - 1 && curr->children[position]->word_end) {
                status = true;
                break;
            }
            curr = curr->children[position];
        }
        else {
            break;
        }
    }

    return status;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{

    FILE *dict = fopen(dictionary, "r");

    // Find file length in bytes
    fseek(dict, 0, SEEK_END);
    unsigned long dict_size = (unsigned long) ftell(dict);
    fseek(dict, 0, SEEK_SET);

    // Load dictionary in memory
    char *dict_buff = malloc(dict_size);
    unsigned long ret = fread(dict_buff, 1, dict_size, dict);
    // Error checking
    if (ret != dict_size) {
        fclose(dict);
        free(dict_buff);
        return false;
    }

    fclose(dict);

    // Create trie
    root = calloc(1, sizeof(Node));
    // Error checking
    if (root == NULL) {
        free(dict_buff);
        return false;
    }
    for (int i = 0, sub; i < dict_size; ++i) {
        Node *curr = root;
        while (true) {
            if (dict_buff[i] == '\n') {
                curr->word_end = true;
                ++word_count;
                break;
            }

            sub = dict_buff[i] - 'a';

            // Add apostrophe (')
            if (sub == -58) {
                sub = 26;
            }

            if (curr->children[sub] == NULL) {
                curr->children[sub] = calloc(1, sizeof(Node));
                // Error checking
                if (curr->children[sub] == NULL) {
                    free(dict_buff);
                    remove_trie(root);
                    return false;
                }
            }

            curr = curr->children[sub];
            ++i;
        }
    }
    free(dict_buff);

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return word_count;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    remove_trie(root);
    return true;
}

void remove_trie(Node *curr)
{
    for (int i = 0; i < CHILDREN; ++i) {
        if (curr->children[i]) {
            remove_trie(curr->children[i]);
        }
    }
    free(curr);
}