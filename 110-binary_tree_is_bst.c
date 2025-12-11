#include "binary_trees.h"

/**
 * is_bst_helper - Helper function to check BST property recursively
 * @tree: Pointer to current node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 *
 * Return: 1 if valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n) &&
		is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if binary tree is valid BST
 * @tree: Pointer to root node
 *
 * Return: 1 if valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
