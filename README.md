# Binary Trees

## 📖 Description
 data structures where each node has at most two children, enabling efficient data operations and serving as foundational building blocks for advanced algorithms and real-world applications like databases and AI systems.

---
## Learning Objectives

* What is a binary tree
* What is the difference between a binary tree and a Binary Search Tree
* What is the possible gain in terms of time complexity compared to linked lists
* What are the depth, the height, the size of a binary tree
* What are the different traversal methods to go through a binary tree
*  What is a complete, a full, a perfect, a balanced binary tree  
  ---

## Requirements  

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project, is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* You are not allowed to use global variables
* No more than 5 functions per file
* You are allowed to use the standard library
* In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you * do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
* The prototypes of all your functions should be included in your header file called binary_trees.h
* Don’t forget to push your header file
* All your header files should be include guarded
  ---

## 📋 File Descriptions

| File | Description |
|------|-------------|
| `binary_trees.h` | Header file containing structure definitions and function prototypes |
| `0-binary_tree_node.c` | Function to create a binary tree node |
| `1-binary_tree_insert_left.c` | Function to insert a node as left-child |
| `2-binary_tree_insert_right.c` | Function to insert a node as right-child |
| `3-binary_tree_delete.c` | Function to delete an entire binary tree |
| `4-binary_tree_is_leaf.c` | Function to check if a node is a leaf |
| `5-binary_tree_is_root.c` | Function to check if a node is a root |
| `6-binary_tree_preorder.c` | Function for pre-order traversal |
| `7-binary_tree_inorder.c` | Function for in-order traversal |
| `8-binary_tree_postorder.c` | Function for post-order traversal |
| `9-binary_tree_height.c` | Function to measure height of a binary tree |
| `10-binary_tree_depth.c` | Function to measure depth of a node |
| `11-binary_tree_size.c` | Function to measure size of a binary tree |
| `12-binary_tree_leaves.c` | Function to count leaves in a binary tree |
| `13-binary_tree_nodes.c` | Function to count nodes with at least 1 child |
| `14-binary_tree_balance.c` | Function to measure balance factor of a binary tree |
| `15-binary_tree_is_full.c` | Function to check if a binary tree is full |
| `16-binary_tree_is_perfect.c` | Function to check if a binary tree is perfect |
| `17-binary_tree_sibling.c` | Function to find the sibling of a node |
| `18-binary_tree_uncle.c` | Function to find the uncle of a node |
| `README.md` | Project documentation |
---

## 🛠️ Compilation Examples
```
gcc -Wall -Wextra -Werror -pedantic -std=gnu89
./0-node
```

---

##   Example output:
```
Noae : 98
Left child : 12
Right child : 402

```

## Authors
* Maryam \ roro13188@gmail.com
* 
