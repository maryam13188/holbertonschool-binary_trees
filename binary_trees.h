#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

/* Binary Search Tree */
typedef struct binary_tree_s bst_t;

/* AVL Tree */
typedef struct binary_tree_s avl_t;

/* Max Binary Heap */
typedef struct binary_tree_s heap_t;

/* Task 0: New node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Task 1: Insert left */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* Task 2: Insert right */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* Task 3: Delete */
void binary_tree_delete(binary_tree_t *tree);

/* Task 4: Is leaf */
int binary_tree_is_leaf(const binary_tree_t *node);

/* Provided helper function (for visualization only) */
void binary_tree_print(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
