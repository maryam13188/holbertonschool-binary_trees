#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search in the tree
 *
 * Return: Pointer to the node containing a value equals to value,
 *         or NULL if tree is NULL or if nothing is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	/* If tree is NULL, return NULL */
	if (tree == NULL)
		return (NULL);

	/* Traverse the tree */
	while (tree != NULL)
	{
		/* If value found at current node */
		if (value == tree->n)
			return ((bst_t *)tree);

		/* If value is less than current node's value, go left */
		if (value < tree->n)
			tree = tree->left;
		/* If value is greater than current node's value, go right */
		else
			tree = tree->right;
	}

	/* Value not found in the tree */
	return (NULL);
}
