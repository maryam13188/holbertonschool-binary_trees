#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	/* Calculate height of left subtree */
	left_height = binary_tree_height(tree->left);
	
	/* Calculate height of right subtree */
	right_height = binary_tree_height(tree->right);
	
	/* Return the larger height + 1 (for current node) */
	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}
