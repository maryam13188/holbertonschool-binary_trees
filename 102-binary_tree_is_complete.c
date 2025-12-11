#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if binary tree is complete
 * @tree: Pointer to root node
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t *q[1024];
	int f = 0, r = 0;
	int empty_spot = 0;

	if (tree == NULL)
		return (0);

	q[r++] = tree;

	while (f < r)
	{
		const binary_tree_t *node = q[f++];

		/* Check left child */
		if (node->left == NULL)
		{
			empty_spot = 1;
		}
		else
		{
			if (empty_spot)
				return (0);
			q[r++] = node->left;
		}

		/* Check right child */
		if (node->right == NULL)
		{
			empty_spot = 1;
		}
		else
		{
			if (empty_spot)
				return (0);
			q[r++] = node->right;
		}
	}

	return (1);
}
