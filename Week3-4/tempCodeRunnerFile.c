void preOrder(node* root) {
    if(root == NULL){
        return;
    }
    printf("%d\n", root-> key);
    preOrder(root -> left);
    preOrder(root-> right);
}