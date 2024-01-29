#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *right;
    struct node *left;
}node;


node * createBT(int data) {
    node* bt = malloc(sizeof(node));
    if (bt == NULL) {
        printf("Memory Failure\n");
        exit(EXIT_FAILURE);
    }
    bt -> key = data;
    bt ->left =NULL;
    bt ->right =NULL;
    return bt;
}

int isEmpty(node* bt){
    return !(bt -> left && bt -> right);
}

void insertLeft(node* bt, node* item){
    if (bt ->left != NULL){
        printf("error this bt already has left child\n");
        exit(EXIT_FAILURE);
    }
    bt->left = item;
}


void insertRight(node* bt, node* item){
    if (bt ->right != NULL){
        printf("error this bt already has right child\n");
        exit(EXIT_FAILURE);
    }
    bt->right = item;
}

node * makeBT(node *item, node *bt1, node *bt2) {
    insertLeft(item,bt1);
    insertRight(item,bt2);
    return item;
}


node* leftSubTree(node* bt) {
    if (bt == NULL || bt->left == NULL) {
        printf("Error: Left Subtree is NULL or does not exist\n");
        exit(EXIT_FAILURE);
    }
    return bt->left;
}

node* rightSubTree(node* bt) {
    if (bt == NULL || bt->right == NULL) {
        printf("Error: Right Subtree is NULL or does not exist\n");
        exit(EXIT_FAILURE);
    }
    return bt->right;
}

int data(node* bt) {
    return bt->key;
}


void freeTree(node* bt) {
    if (bt != NULL) {
        freeTree(bt->left);
        freeTree(bt->right);
        free(bt);
    }
}


void preOrder(node* root) {
    if(root == NULL){
        return;
    }
    printf("%d\t", root-> key);
    preOrder(root -> left);
    preOrder(root-> right);
}


void inOrder(node* root) {
    if(root == NULL){
        return;
    }
    inOrder(root -> left);
    printf("%d\t", root-> key);
    inOrder(root-> right);
}

void postOrder(node* root) {
    if(root == NULL){
        return;
    }
    postOrder(root -> left);
    postOrder(root-> right);
    printf("%d\t", root-> key);

}
int main() {
    // 레벨 0
    node* root = createBT(1);

    // 레벨 1
    node* node_2 = createBT(2);
    node* node_3 = createBT(3);
    makeBT(root, node_2, node_3);

    // 레벨 2
    node* node_4 = createBT(4);
    node* node_5 = createBT(5);
    makeBT(node_2, node_4, node_5);

    node* node_6 = createBT(6);
    node* node_7 = createBT(7);
    makeBT(node_3, node_6, node_7);

    // 레벨 3
    node* node_8 = createBT(8);
    node* node_9 = createBT(9);
    makeBT(node_4, node_8, node_9);

    node* node_10 = createBT(10);
    node* node_11 = createBT(11);
    makeBT(node_5, node_10, node_11);

    node* node_12 = createBT(12);
    node* node_13 = createBT(13);
    makeBT(node_6, node_12, node_13);

    node* node_14 = createBT(14);
    node* node_15 = createBT(15);
    makeBT(node_7, node_14, node_15);
    
    printf("\nPREORDER:\t");
    preOrder(root);
    printf("\nINORDER:\t");
    inOrder(root);
    printf("\nPOSTORDER:\t");
    postOrder(root);
    
    // 메모리 해제
    freeTree(root);

    return 0;
}
