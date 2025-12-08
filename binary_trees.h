#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
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

/* Binary Search Tree type */
typedef struct binary_tree_s bst_t;

/* AVL Tree type */
typedef struct binary_tree_s avl_t;

/* Max Binary Heap type */
typedef struct binary_tree_s heap_t;

/* Function to print binary tree */
void binary_tree_print(const binary_tree_t *tree);

/* Task 0: Create node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Task 1: Insert left */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* Task 2: Insert right */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* Task 3: Delete tree */
void binary_tree_delete(binary_tree_t *tree);

/* Task 4: Check if leaf */
int binary_tree_is_leaf(const binary_tree_t *node);

/* Task 6: Pre-order traversal */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

#endif /* BINARY_TREES_H */
