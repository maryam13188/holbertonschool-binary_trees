#include "binary_trees.h"

/* Forward declaration of height function */
int height(const binary_tree_t *tree);

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int left_height, right_height;
    
    if (tree == NULL)
        return (0);
    
    left_height = tree->left ? 1 + height(tree->left) : 0;
    right_height = tree->right ? 1 + height(tree->right) : 0;
    
    return (left_height - right_height);
}

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree, 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
    int left_height, right_height;
    
    if (tree == NULL)
        return (0);
    
    left_height = height(tree->left);
    right_height = height(tree->right);
    
    return (1 + (left_height > right_height ? left_height : right_height));
}
