#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>

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

/* Typedefs for special trees */
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/* Function prototypes - Task 0 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Function prototypes - Task 1 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* Function prototypes - Task 2 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* Function prototypes - Task 3 */
void binary_tree_delete(binary_tree_t *tree);

/* Helper function for testing (provided, don't push) */
void binary_tree_print(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
