#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	/* If tree is NULL, nothing to delete */
	if (tree == NULL)
		return;

	/* Recursively delete the left subtree (DFS post-order) */
	binary_tree_delete(tree->left);
	
	/* Recursively delete the right subtree (DFS post-order) */
	binary_tree_delete(tree->right);
	
	/* After both subtrees are deleted, free the current node */
	free(tree);
}
