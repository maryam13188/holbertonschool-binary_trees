#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree, 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    
    int left_height = height(tree->left);
    int right_height = height(tree->right);
    
    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * max - Returns the maximum of two integers
 * @a: First integer
 * @b: Second integer
 * Return: Maximum value
 */
int max(int a, int b)
{
    return (a > b ? a : b);
}

/**
 * get_balance - Computes the balance factor of an AVL tree node
 * @node: Pointer to the node
 * Return: Balance factor
 */
int get_balance(const avl_t *node)
{
    if (node == NULL)
        return (0);
    return (height(node->left) - height(node->right));
}

/**
 * avl_insert_recursive - Recursively inserts a value into an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @parent: Pointer to the parent node
 * @new_node: Double pointer to store the newly created node
 * @value: Value to insert
 * Return: Pointer to the root of the subtree after insertion and balancing
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
                           avl_t **new_node, int value)
{
    int balance;
    
    if (*tree == NULL)
    {
        *new_node = binary_tree_node(parent, value);
        if (*new_node == NULL)
            return (NULL);
        return (*new_node);
    }
    
    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert_recursive(&((*tree)->left), *tree,
                                            new_node, value);
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert_recursive(&((*tree)->right), *tree,
                                             new_node, value);
    }
    else
    {
        /* Value already exists, return the existing node */
        *new_node = *tree;
        return (*tree);
    }
    
    /* Update height and get balance factor */
    balance = get_balance(*tree);
    
    /* Left Left Case */
    if (balance > 1 && value < (*tree)->left->n)
        return binary_tree_rotate_right(*tree);
    
    /* Right Right Case */
    if (balance < -1 && value > (*tree)->right->n)
        return binary_tree_rotate_left(*tree);
    
    /* Left Right Case */
    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        return binary_tree_rotate_right(*tree);
    }
    
    /* Right Left Case */
    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        return binary_tree_rotate_left(*tree);
    }
    
    return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to insert
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node = NULL;
    
    if (tree == NULL)
        return (NULL);
    
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }
    
    *tree = avl_insert_recursive(tree, NULL, &new_node, value);
    return (new_node);
}
