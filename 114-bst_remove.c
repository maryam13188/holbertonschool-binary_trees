#include "binary_trees.h"

/**
 * bst_find_min - Finds the minimum value node in a BST
 * @node: Pointer to the root node
 * Return: Pointer to the node with minimum value
 */
static bst_t *bst_find_min(bst_t *node)
{
	if (node == NULL)
		return (NULL);

	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove_one_child - Removes node with one or no child
 * @root: Node to remove
 * Return: New node to replace the removed one
 */
static bst_t *bst_remove_one_child(bst_t *root)
{
	bst_t *temp = NULL;

	if (root->left == NULL)
	{
		temp = root->right;
		if (temp != NULL)
			temp->parent = root->parent;
		free(root);
		return (temp);
	}
	else if (root->right == NULL)
	{
		temp = root->left;
		if (temp != NULL)
			temp->parent = root->parent;
		free(root);
		return (temp);
	}

	return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove in the tree
 * Return: Pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
		if (root->left != NULL)
			root->left->parent = root;
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
		if (root->right != NULL)
			root->right->parent = root;
	}
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			return (bst_remove_one_child(root));
		}
		else
		{
			/* Node with two children */
			temp = bst_find_min(root->right);
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
			if (root->right != NULL)
				root->right->parent = root;
		}
	}

	return (root);
}
