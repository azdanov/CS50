/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

#define SIZE 150000

typedef struct list_node{
    char word[LENGTH+1];
    struct list_node *next;
} list_node;

list_node **dict;

unsigned int dictionary_size = 0;

/*
 * MurmurHash2 by Austin Appleby
 */
unsigned int MurmurHash2 ( char * key, unsigned int len)
{
    const unsigned int m = 0x5bd1e995;
    const unsigned int seed = 0;
    const int r = 24;

    unsigned int h = seed ^ len;

    const unsigned char * data = (const unsigned char *)key;
    unsigned int k;

    while (len >= 4)
    {
        k  = data[0];
        k |= data[1] << 8;
        k |= data[2] << 16;
        k |= data[3] << 24;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
    }

    switch (len)
    {
        case 3:
            h ^= data[2] << 16;
        case 2:
            h ^= data[1] << 8;
        case 1:
            h ^= data[0];
            h *= m;
    };

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // get length + copy
    size_t word_len = strlen(word);
    char *needle = malloc(sizeof(char) * word_len);

    for (int i = 0; i < word_len; ++i) {
        *(needle + i) = tolower(*(word + i));
    }

    unsigned int hash = MurmurHash2(needle, word_len) % SIZE;

    list_node *l_list = *(dict + hash);
    while(l_list) {
        if(strcmp(l_list->word, needle) == 0) {
            free(needle);
            return true;
        } else {
            l_list = l_list->next;
        }
    }
    free(needle);
    return false;
}

/*
 * Creates a new node for a linked list
 */
bool createNode(const char *buff, list_node **current) {
    // create new
    list_node *new_node = malloc(sizeof(list_node));
    if(!new_node) {
        return false;
    }
    // copy
    strcpy(new_node->word, buff);
    new_node->next = NULL;

    // add either new or to the last
    if(*current == NULL) {
        *current = new_node;
    } else {
        (*current)->next = new_node;
    }

    ++dictionary_size;
    return true;
}

/*
 * Loads dictionary into memory.  Returns true if successful else false.
 */

bool load(const char* dictionary)
{
    FILE *fp = fopen(dictionary, "r");
    if(!fp) {
        perror("Can't open dictionary");
        return false;
    }

    char buff[LENGTH+1];

    unsigned int hash;

    dict = calloc(SIZE, sizeof(list_node *));

    list_node **bucket = NULL;
    list_node *l_list = NULL;

    while((fscanf(fp, " %s", buff)) != EOF) {
        // get bucket index
        hash = MurmurHash2(buff, strlen(buff)) % SIZE;
        bucket = dict + hash;
        l_list = *bucket;

        // bucket is empty
        if(l_list == NULL) {
            // try to create and fill out a node
            if(!createNode(buff, bucket)) {
                unload();
                fclose(fp);
                return false;
            }
        }
        // bucket is not empty
        else
        {
            // find last node
            while(l_list->next) {
                l_list = l_list->next;
            }
            // try to create and fill out a node
            if(!createNode(buff, &l_list)) {
                unload();
                fclose(fp);
                return false;
            }
        }
    }
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if(!dictionary_size) {
        return 0;
    }

    return dictionary_size;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    if(!dictionary_size) {
        return false;
    }

    list_node *current, *next;

    for (unsigned int i = 0; i < SIZE; ++i) {
        current = *(dict + i);
        if(current == NULL) {
            continue;
        } else {
            while(current != NULL) {
                next = current->next;
                free(current);
                current = next;
            }
        }
    }

    free(dict);
    return true;
}
