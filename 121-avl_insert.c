#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree
 */
int height(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = height(tree->left);
    right_height = height(tree->right);

    return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * balance_factor - Computes the balance factor of a binary tree node
 * @tree: Pointer to the node
 * Return: Balance factor (height(left) - height(right))
 */
int balance_factor(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (height(tree->left) - height(tree->right));
}

/**
 * rotate_right - Performs a right rotation
 * @y: Node to rotate around
 * Return: New root node after rotation
 */
binary_tree_t *rotate_right(binary_tree_t *y)
{
    binary_tree_t *x = y->left;
    binary_tree_t *T2 = x->right;

    x->right = y;
    y->left = T2;

    if (T2)
        T2->parent = y;

    x->parent = y->parent;
    y->parent = x;

    return (x);
}

/**
 * rotate_left - Performs a left rotation
 * @x: Node to rotate around
 * Return: New root node after rotation
 */
binary_tree_t *rotate_left(binary_tree_t *x)
{
    binary_tree_t *y = x->right;
    binary_tree_t *T2 = y->left;

    y->left = x;
    x->right = T2;

    if (T2)
        T2->parent = x;

    y->parent = x->parent;
    x->parent = y;

    return (y);
}

/**
 * insert_node - Recursively inserts a node in AVL tree
 * @tree: Double pointer to the root node
 * @parent: Parent node
 * @value: Value to insert
 * Return: Pointer to the new node or NULL
 */
avl_t *insert_node(avl_t **tree, avl_t *parent, int value)
{
    avl_t *new_node;
    int balance;

    if (*tree == NULL)
    {
        new_node = binary_tree_node(parent, value);
        if (new_node == NULL)
            return (NULL);
        *tree = new_node;
        return (new_node);
    }

    if (value < (*tree)->n)
    {
        new_node = insert_node(&((*tree)->left), *tree, value);
        if (new_node == NULL)
            return (NULL);
    }
    else if (value > (*tree)->n)
    {
        new_node = insert_node(&((*tree)->right), *tree, value);
        if (new_node == NULL)
            return (NULL);
    }
    else
    {
        return (*tree); /* Value already exists */
    }

    /* Update balance factor and rebalance if needed */
    balance = balance_factor(*tree);

    /* Left Left Case */
    if (balance > 1 && value < (*tree)->left->n)
    {
        *tree = rotate_right(*tree);
        if ((*tree)->parent == NULL)
            (*tree)->parent = parent;
    }
    /* Right Right Case */
    else if (balance < -1 && value > (*tree)->right->n)
    {
        *tree = rotate_left(*tree);
        if ((*tree)->parent == NULL)
            (*tree)->parent = parent;
    }
    /* Left Right Case */
    else if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = rotate_left((*tree)->left);
        if ((*tree)->left)
            (*tree)->left->parent = *tree;
        *tree = rotate_right(*tree);
        if ((*tree)->parent == NULL)
            (*tree)->parent = parent;
    }
    /* Right Left Case */
    else if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = rotate_right((*tree)->right);
        if ((*tree)->right)
            (*tree)->right->parent = *tree;
        *tree = rotate_left(*tree);
        if ((*tree)->parent == NULL)
            (*tree)->parent = parent;
    }

    return (new_node);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node;

    if (tree == NULL)
        return (NULL);

    /* If tree is empty, create root node */
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    new_node = insert_node(tree, NULL, value);

    /* Find the root after rotations */
    while ((*tree)->parent != NULL)
        *tree = (*tree)->parent;

    return (new_node);
}
