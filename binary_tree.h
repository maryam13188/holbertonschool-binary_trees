#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/* Helper function for printing (provided) */
void binary_tree_print(const binary_tree_t *);

/* Task 0: Create a binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Task 14: Measure the balance factor of a binary tree */
int binary_tree_balance(const binary_tree_t *tree);

/* Task 15: Check if a binary tree is full */
int binary_tree_is_full(const binary_tree_t *tree);

/* Task 16: Check if a binary tree is perfect */
int binary_tree_is_perfect(const binary_tree_t *tree);

/* Task 103: Rotate a binary tree to the left */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);

/* Task 104: Rotate a binary tree to the right */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

/* Task 121: AVL Tree Insertion */
avl_t *avl_insert(avl_t **tree, int value);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, avl_t **new_node, int value);

/* Helper functions for AVL insertion */
int height(const binary_tree_t *tree);
int max(int a, int b);
int get_balance(const avl_t *node);

#endif /* BINARY_TREES_H */
