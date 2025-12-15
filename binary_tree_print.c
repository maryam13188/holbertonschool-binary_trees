#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_print - Prints a binary tree in a readable way
 * @tree: pointer to the root node of the tree
 */
void binary_tree_print(const binary_tree_t *tree)
{
    int i;
    if (!tree)
        return;

    if (tree->right)
    {
        i = 1;
        while (i--)
            printf("    ");
        binary_tree_print(tree->right);
    }

    printf("%d\n", tree->n);

    if (tree->left)
    {
        i = 1;
        while (i--)
            printf("    ");
        binary_tree_print(tree->left);
    }
}

