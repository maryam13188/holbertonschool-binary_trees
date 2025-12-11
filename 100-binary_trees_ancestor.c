#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node
 * @tree: Pointer to the node
 *
 * Return: Depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
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
 * binary_trees_ancestor - Finds lowest common ancestor
 * @first: First node
 * @second: Second node
 *
 * Return: Pointer to LCA, or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
    size_t d1, d2;
    const binary_tree_t *n1, *n2;

    if (!first || !second)
        return (NULL);

    if (first == second)
        return ((binary_tree_t *)first);

    d1 = binary_tree_depth(first);
    d2 = binary_tree_depth(second);
    n1 = first;
    n2 = second;

    while (d1 > d2)
    {
        n1 = n1->parent;
        d1--;
    }

    while (d2 > d1)
    {
        n2 = n2->parent;
        d2--;
    }

    while (n1 && n2 && n1 != n2)
    {
        n1 = n1->parent;
        n2 = n2->parent;
    }

    return (n1 == n2 ? (binary_tree_t *)n1 : NULL);
}
