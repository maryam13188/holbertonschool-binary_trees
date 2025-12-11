#include "binary_trees.h"

/**
 * array_to_bst - Builds Binary Search Tree from array
 * @array: Pointer to first element of array
 * @size: Number of elements in array
 *
 * Return: Pointer to root node, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		bst_insert(&tree, array[i]);

	return (tree);
}
