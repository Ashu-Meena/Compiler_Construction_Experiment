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

    /*
             =
            / \
           a   +
              / \
             b   *
                / \
               c   d
    */

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
