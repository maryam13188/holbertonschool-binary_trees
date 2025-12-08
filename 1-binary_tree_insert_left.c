#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node, *old_left;

    /* Check if parent is NULL */
    if (parent == NULL)
        return (NULL);

    /* Create the new node */
    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return (NULL);

    /* If parent already has a left child */
    if (parent->left != NULL)
    {
        /* Save the old left child */
        old_left = parent->left;
        
        /* Set new node as parent's left child */
        parent->left = new_node;
        
        /* Set old left child as left child of new node */
        new_node->left = old_left;
        
        /* Update parent pointer of old left child */
        old_left->parent = new_node;
    }
    else
    {
        /* Simply set new node as left child */
        parent->left = new_node;
    }

    return (new_node);
}
