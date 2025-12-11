#include "binary_trees.h"

/**
 * bst_search - Searches for value in Binary Search Tree
 * @tree: Pointer to root node of BST
 * @value: Value to search for
 *
 * Return: Pointer to node containing value, or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	while (tree != NULL)
	{
		if (value == tree->n)
			return ((bst_t *)tree);

		if (value < tree->n)
			tree = tree->left;
		else
			tree = tree->right;
	}

	return (NULL);
}
