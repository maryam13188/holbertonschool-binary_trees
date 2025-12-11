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
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
    const binary_tree_t *temp1, *temp2;
    int depth1 = 0, depth2 = 0;

    /* If either node is NULL, return NULL */
    if (!first || !second)
        return (NULL);

    /* If both nodes are the same, return the node itself */
    if (first == second)
        return ((binary_tree_t *)first);

    /* Calculate depth of first node */
    temp1 = first;
    while (temp1->parent)
    {
        depth1++;
        temp1 = temp1->parent;
    }

    /* Calculate depth of second node */
    temp2 = second;
    while (temp2->parent)
    {
        depth2++;
        temp2 = temp2->parent;
    }

    /* Reset pointers to original nodes */
    temp1 = first;
    temp2 = second;

    /* Move the deeper node up until both are at same depth */
    while (depth1 > depth2)
    {
        temp1 = temp1->parent;
        depth1--;
    }

    while (depth2 > depth1)
    {
        temp2 = temp2->parent;
        depth2--;
    }

    /* Move both nodes up together until they meet or reach NULL */
    while (temp1 && temp2)
    {
        if (temp1 == temp2)
            return ((binary_tree_t *)temp1);
        temp1 = temp1->parent;
        temp2 = temp2->parent;
    }

    /* If no common ancestor found, return NULL */
    return (NULL);
}
