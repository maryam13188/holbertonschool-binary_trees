#include "binary_trees.h"
#include <limits.h>

/**
 * max_int - Returns the maximum of two integers
 * @a: First integer
 * @b: Second integer
 * Return: Maximum value
 */
static int max_int(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * abs_diff - Returns absolute difference between two integers
 * @a: First integer
 * @b: Second integer
 * Return: Absolute difference
 */
static int abs_diff(int a, int b)
{
	return (a > b ? a - b : b - a);
}

/**
 * is_avl_helper - Helper function to check AVL properties
 * @tree: Pointer to the root node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 * @height: Pointer to store height
 * Return: 1 if valid AVL, 0 otherwise
 */
static int is_avl_helper(const binary_tree_t *tree,
						int min, int max, int *height)
{
	int left_height = 0, right_height = 0;
	int left_avl, right_avl;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}

	if (tree->n <= min || tree->n >= max)
		return (0);

	left_avl = is_avl_helper(tree->left, min, tree->n, &left_height);
	right_avl = is_avl_helper(tree->right, tree->n, max, &right_height);

	if (!left_avl || !right_avl)
		return (0);

	if (abs_diff(left_height, right_height) > 1)
		return (0);

	*height = 1 + max_int(left_height, right_height);
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX, &height));
}
