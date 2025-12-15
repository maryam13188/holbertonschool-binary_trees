#include "binary_trees.h"
#include <stdlib.h>

/**
 * avl_insert_helper - Helper function to insert a value in BST manner
 * @tree: Double pointer to the root of subtree
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
static avl_t *avl_insert_helper(avl_t **tree, int value)
{
    avl_t *node;

    if (!tree)
        return (NULL);

    if (*tree == NULL)
        return (binary_tree_node(NULL, value));

    if (value < (*tree)->n)
    {
        node = avl_insert_helper(&(*tree)->left, value);
        if (!node)
            return (NULL);
        (*tree)->left->parent = *tree;
    }
    else if (value > (*tree)->n)
    {
        node = avl_insert_helper(&(*tree)->right, value);
        if (!node)
            return (NULL);
        (*tree)->right->parent = *tree;
    }
    else
        return (*tree);

    return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL Tree
 * @tree: Double pointer to the root of AVL Tree
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *root, *node;

    if (!tree)
        return (NULL);

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    root = *tree;
    node = avl_insert_helper(tree, value);

    /* Balance the tree after insertion */
    while (root->parent)
        root = root->parent;

    *tree = root;

    return (node);
}

