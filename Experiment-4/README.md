# Experiment 4: Construction of a Parse Tree for an Arithmetic Statement in C

[![Run on OneCompiler (Auto-Copy)](https://img.shields.io/badge/Run_Code_(Auto--Copy)-OneCompiler-2ecc71?style=for-the-badge&logo=c)](https://ashu-meena.github.io/Compiler_Construction_Experiment/run.html?exp=4&target=onecompiler)
[![Run on OnlineGDB (Auto-Copy)](https://img.shields.io/badge/Run_Code_(Auto--Copy)-OnlineGDB-3498db?style=for-the-badge&logo=c)](https://ashu-meena.github.io/Compiler_Construction_Experiment/run.html?exp=4&target=onlinegdb)
[![Interactive Web Portal](https://img.shields.io/badge/Web_Portal-All_Exps-6f42c1?style=for-the-badge&logo=github)](https://ashu-meena.github.io/Compiler_Construction_Experiment/)

## Aim
To construct a binary parse tree for the arithmetic statement `a = b + c * d` in C and perform Inorder and Preorder traversals.

## Parse Tree Representation
```text
         =
        / \
       a   +
          / \
         b   *
            / \
           c   d
```

## Algorithm
1. Start the program.
2. Define a structure `Node` containing:
   - `data`: character for operator or operand.
   - `left`: pointer to the left child node.
   - `right`: pointer to the right child node.
3. Define helper function `createNode(char data)`:
   - Dynamically allocate memory for a new node.
   - Set node's data and initialize `left` and `right` pointers to `NULL`.
4. Construct the tree for statement `a = b + c * d`:
   - Root is `=`.
   - Left child of `=` is `a`.
   - Right child of `=` is `+`.
   - Left child of `+` is `b`.
   - Right child of `+` is `*`.
   - Left child of `*` is `c`.
   - Right child of `*` is `d`.
5. Implement traversal functions:
   - **Inorder (`Left -> Root -> Right`):** Produces the infix notation (`a=b+c*d`).
   - **Preorder (`Root -> Left -> Right`):** Produces prefix notation (`=a+b*cd`).
6. Print the traversal results.
7. Terminate the program.

## Program Code
See [`parse_tree.c`](./parse_tree.c):

```c
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(char data)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct Node *root;

    root = createNode('=');

    root->left = createNode('a');

    root->right = createNode('+');
    root->right->left = createNode('b');

    root->right->right = createNode('*');
    root->right->right->left = createNode('c');
    root->right->right->right = createNode('d');

    printf("Inorder Traversal: ");
    inorder(root);

    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);

    printf("\n");

    return 0;
}
```

## Sample Output
```text
Inorder Traversal: a=b+c*d
Preorder Traversal: =a+b*cd
```

## How to Run Locally

### Using GCC (MinGW on Windows / Linux / macOS)
```bash
gcc parse_tree.c -o parse_tree
./parse_tree
```
