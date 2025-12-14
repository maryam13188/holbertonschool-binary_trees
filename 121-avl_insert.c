#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;
	int balance;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->left = new_node;
		}
		else
		{
			new_node = avl_insert(&(*tree)->left, value);
		}
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->right = new_node;
		}
		else
		{
			new_node = avl_insert(&(*tree)->right, value);
		}
	}
	else
	{
		return (*tree);
	}

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
	{
		*tree = (avl_t *)binary_tree_rotate_right((binary_tree_t *)*tree);
		return (new_node ? new_node : *tree);
	}
	if (balance < -1 && value > (*tree)->right->n)
	{
		*tree = (avl_t *)binary_tree_rotate_left((binary_tree_t *)*tree);
		return (new_node ? new_node : *tree);
	}
	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = (avl_t *)binary_tree_rotate_left((binary_tree_t *)(*tree)->left);
		*tree = (avl_t *)binary_tree_rotate_right((binary_tree_t *)*tree);
		return (new_node ? new_node : *tree);
	}
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = (avl_t *)binary_tree_rotate_right((binary_tree_t *)(*tree)->right);
		*tree = (avl_t *)binary_tree_rotate_left((binary_tree_t *)*tree);
		return (new_node ? new_node : *tree);
	}

	return (new_node);
}
