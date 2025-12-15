#include "binary_trees.h"

/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Double pointer to the root node
 * @value: Value to store in the new node
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *node;

    if (!tree)
        return (NULL);

    /* Empty tree case */
    if (*tree == NULL)
    {
        node = binary_tree_node(NULL, value);
        if (!node)
            return (NULL);
        *tree = node;
        return (node);
    }

    /* Standard BST insertion */
    node = bst_insert(tree, value);
    if (!node)
        return (NULL);

    /* Balance the tree from the inserted node up to the root */
    while (node)
    {
        int balance = binary_tree_balance(node);

        if (balance > 1 && value < node->left->n) /* Left Left */
            node = binary_tree_rotate_right(node);
        else if (balance < -1 && value > node->right->n) /* Right Right */
            node = binary_tree_rotate_left(node);
        else if (balance > 1 && value > node->left->n) /* Left Right */
        {
            node->left = binary_tree_rotate_left(node->left);
            node = binary_tree_rotate_right(node);
        }
        else if (balance < -1 && value < node->right->n) /* Right Left */
        {
            node->right = binary_tree_rotate_right(node->right);
            node = binary_tree_rotate_left(node);
        }

        if (!node->parent) /* reached root */
            *tree = node;

        node = node->parent;
    }

    /* Return pointer to the inserted node */
    return (bst_search(*tree, value));
}

/**
 * bst_insert - Inserts a node in a BST (helper for AVL)
 * @tree: Double pointer to the root node
 * @value: Value to insert
 * Return: Pointer to inserted node
 */
static avl_t *bst_insert(avl_t **tree, int value)
{
    avl_t *node = *tree, *parent = NULL, *new;

    while (node)
    {
        parent = node;
        if (value < node->n)
            node = node->left;
        else if (value > node->n)
            node = node->right;
        else
            return (node); /* Duplicate, return existing */
    }

    new = binary_tree_node(parent, value);
    if (!new)
        return (NULL);

    if (value < parent->n)
        parent->left = new;
    else
        parent->right = new;

    return (new);
}

/**
 * bst_search - Searches for a value in BST
 * @tree: Pointer to root
 * @value: Value to search
 * Return: Pointer to node with value
 */
static avl_t *bst_search(avl_t *tree, int value)
{
    if (!tree)
        return (NULL);

    if (value == tree->n)
        return (tree);
    if (value < tree->n)
        return (bst_search(tree->left, value));
    return (bst_search(tree->right, value));
}

