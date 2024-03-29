#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Node *root = NULL; //Global variable

void Treecreate() {
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100); // create a queue..

    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    // now set root Node data, lchild & rchild...
    root->data = x;
    root->lchild = root->rchild = NULL;

    // Insert above Node in Queue..
    enqueue(&q, root);

    while (!isEmpty(q)) {
        p = dequeue(&q);
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            // insert this new node to Queue..
            enqueue(&q, t);
        }
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void Preorder(struct Node *p) {
    if (p) {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Node *p) {
    if (p) {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void freeTree(struct Node *node) {
    if (node == NULL) {
        return; // Base case: if the node is NULL, return
    }

    // Recursively free the left subtree
    freeTree(node->lchild);
    // Recursively free the right subtree
    freeTree(node->rchild);

    // Free the memory allocated for the current node
    free(node);
}

int main() {
    Treecreate();
    printf("Preorder: ");
    Preorder(root);
    printf("\nPostorder: ");
    Postorder(root);
    printf("\n");

    // Free the memory allocated for the tree
    freeTree(root);
    root = NULL; // Optional: Set root to NULL after freeing the memory

    // Print the tree after freeing the memory
    printf("\nAfter freeing memory:\n");
    printf("Preorder: ");
    Preorder(root); // This will not print anything because the tree is empty
    printf("\nPostorder: ");
    Postorder(root); // This will not print anything because the tree is empty
    printf("\n");


    return 0;
}
