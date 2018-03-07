/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/** We define the node struct. **/
typedef struct node
{
    bool is_word;
    struct node *children[27];
}
node;

node *root = NULL;
int wordsInDictionary = 0;

/** Function declarations **/
node *nextNode();
bool freeWithRecursion(node *cursor);


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // create a var_node to navigate through the trie
    node *var_node = root;
    char temp[strlen(word)];
    int c;

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] != '\0')
        {
            if (isalpha(word[i]))
            {
                temp[i] = tolower(word[i]);
                c = temp[i] - 97;
            }
            else if (word[i] == '\'')
            {
                c = word[i] - 13;
            }

            if (var_node -> children[c] == NULL)
            {
                return false;
            }

            else if (var_node -> children[c] != NULL)
            {
                // move to next letter
                var_node = var_node -> children[c];
            }
        }

    }

    // if we reached this point without returning false, the word is correct.
    if (var_node -> is_word == true)
    {
        return true;
    }

    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    /** We are going to implement a trie data structure for the dictionary**/

    FILE *dic_file = fopen(dictionary, "r");
    if (dic_file == NULL)
    {
        fprintf(stderr, "Could not open dictionary file\n");
        return false;
    }

    /** Initiate the root node and set a pointer, var_node, to it that will undergo variation. **/
    root = nextNode();
    // var_node is a variable containing the address of root. root is now the root node.
    node *var_node = root;
    int c;

    /** We'll loop through chars of a word and move on to the next word when c = '\n'. **/
    while ((c = fgetc(dic_file)) != EOF)
    {
        /** In this case, we're looping through the letters of a word **/
        if (c != '\n')
        {
            /** The index of 0 is given to a, and 26 to '\''. **/
            if (isalpha(c))
            {
                c -= 97;
            }
            else
            {
                c -= 13;
            }

            /** If node is available **/
            if (var_node -> children[c] == NULL)
            {
                // create a new node; put it in children[c].
                node *next_node = nextNode();
                var_node -> children[c] = next_node;
                // update var_node to point at the current node.
                var_node = var_node -> children[c];
            }
            /** If node is already occupied **/
            else if (var_node -> children[c] != NULL)
            {
                // update var_node to point at the current node.
                var_node = var_node -> children[c];
            }
        }

        /** In this case, we have completed a word. **/
        else if (c == '\n')
        {
            var_node -> is_word = true;
            var_node = root;
            wordsInDictionary++;
        }

    }

    fclose(dic_file);
    return true;

}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return wordsInDictionary;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    node *cursor = root;
    if (freeWithRecursion(cursor))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// returns a pointer to a node
node* nextNode(void)
{
    //creates a new node
    node *next_node = malloc(sizeof(node));
    next_node -> is_word = false;
    for (int i = 0; i < 27; i++)
    {
        next_node -> children[i] = NULL;
    }
    return next_node;
}

bool freeWithRecursion(node *cursor)
{
    for (int i = 0; i < 27; i++)
    {
        if (cursor -> children[i] != NULL)
        {
            freeWithRecursion(cursor -> children[i]);
        }
    }

    free(cursor);
    return true;
}