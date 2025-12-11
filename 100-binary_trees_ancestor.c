#include <stddef.h>

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

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * Return: Depth of the node, 0 if tree is NULL
 */
static size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    if (!tree)
        return (0);

    while (tree->parent)
    {
        depth++;
        tree = tree->parent;
    }

    return (depth);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
    size_t depth_first, depth_second;
    const binary_tree_t *temp_first, *temp_second;

    if (!first || !second)
        return (NULL);

    /* If both nodes are the same, the LCA is the node itself */
    if (first == second)
        return ((binary_tree_t *)first);

    /* Get the depth of each node from the root */
    depth_first = binary_tree_depth(first);
    depth_second = binary_tree_depth(second);

    /* Start from each node */
    temp_first = first;
    temp_second = second;

    /* Move the deeper node up until both are at the same level */
    while (depth_first > depth_second)
    {
        temp_first = temp_first->parent;
        depth_first--;
    }

    while (depth_second > depth_first)
    {
        temp_second = temp_second->parent;
        depth_second--;
    }

    /* Now both nodes are at the same depth, move up together */
    while (temp_first && temp_second && temp_first != temp_second)
    {
        temp_first = temp_first->parent;
        temp_second = temp_second->parent;
    }

    /* If we found a common ancestor, return it */
    return (temp_first == temp_second ? (binary_tree_t *)temp_first : NULL);
}
