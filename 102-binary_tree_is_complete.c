#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if binary tree is complete
 * @tree: Pointer to root node
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t *q[1000];
	int front = 0, back = 0, flag = 0;

	if (!tree)
		return (0);

	q[back++] = tree;

	while (front < back)
	{
		const binary_tree_t *node = q[front++];

		if (!node->left)
			flag = 1;
		else if (flag)
			return (0);
		else
			q[back++] = node->left;

		if (!node->right)
			flag = 1;
		else if (flag)
			return (0);
		else
			q[back++] = node->right;
	}

	return (1);
}
