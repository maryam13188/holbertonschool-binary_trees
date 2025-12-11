#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs right rotation on binary tree
 * @tree: Pointer to root node of tree to rotate
 *
 * Return: Pointer to new root node after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *temp;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	pivot = tree->left;
	temp = pivot->right;

	/* Perform rotation */
	pivot->right = tree;
	tree->left = temp;

	/* Update parent pointers */
	if (temp != NULL)
		temp->parent = tree;

	pivot->parent = tree->parent;
	tree->parent = pivot;

	/* Update parent's child pointer */
	if (pivot->parent != NULL)
	{
		if (pivot->parent->left == tree)
			pivot->parent->left = pivot;
		else
			pivot->parent->right = pivot;
	}

	return (pivot);
}
