// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;
int totalWords = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    node *cursor;
    cursor = table[hash(word)];
    if (strcasecmp(word, cursor->word) == 0)
    {
        return true;
    }
    while (cursor->next != NULL)
    {
        cursor = cursor->next;
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int n = (int) tolower(word[0]) - 97;
    return n;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char *new_word = malloc(sizeof(LENGTH));
    if (new_word == NULL)
    {
        return false;
    }
    while (fscanf(file, "%s", new_word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, new_word);
        int hash_value = hash(new_word);
        n->next = table[hash_value];
        table[hash_value] = n;
        totalWords++;
    }
    fclose(file);
    free(new_word);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (totalWords > 0)
    {
        return totalWords;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node *cursor;
    node *temp;
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }
        cursor = table[i];
        temp = cursor;
        while (cursor->next != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
        free(cursor);
    }
    return true;
}
