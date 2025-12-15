#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_insert - Inserts a value into a BST (helper for AVL insert)
 * @tree: Double pointer to the root node
 * @value: Value to insert
 * Return: Pointer to the created node
 */
avl_t *bst_insert(avl_t **tree, int value)
{
	avl_t *node = NULL;

	if (!tree)
		return (NULL);

	if (!*tree)
		return (binary_tree_node(NULL, value));

	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
			(*tree)->left = binary_tree_node(*tree, value);
		else
			node = bst_insert(&(*tree)->left, value);
	}
	else if (value > (*tree)->n)
	{
		if (!(*tree)->right)
			(*tree)->right = binary_tree_node(*tree, value);
		else
			node = bst_insert(&(*tree)->right, value);
	}
	if ((*tree)->left && (*tree)->left->n == value)
		return ((*tree)->left);
	if ((*tree)->right && (*tree)->right->n == value)
		return ((*tree)->right);
	return (node);
}

/**
 * avl_insert - Inserts a value in an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to insert
 * Return: Pointer to the created node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;

	if (!tree)
		return (NULL);

	new_node = bst_insert(tree, value);

	if (!new_node)
		return (NULL);

	while (*tree)
	{
		binary_tree_balance(*tree);
		*tree = (*tree)->parent;
	}

	return (new_node);
}

