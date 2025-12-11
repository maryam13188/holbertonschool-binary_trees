#include <stddef.h>

struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
    const binary_tree_t *n1, *n2;

    if (!first || !second)
        return (NULL);

    if (first == second)
        return ((binary_tree_t *)first);

    for (n1 = first; n1; n1 = n1->parent)
        for (n2 = second; n2; n2 = n2->parent)
            if (n1 == n2)
                return ((binary_tree_t *)n1);

    return (NULL);
}
