#include <stdio.h>
#include <stdlib.h>



typedef struct Node {
    int data;
    struct Node* next;
} node;

typedef struct List
{
    node* head;
} lkList;


void nodeAppend(lkList* list, int x){
    // 새로운 노드 생성
    node* newNode = malloc(sizeof(node));
    if (newNode == NULL){
        printf("메모리할당실패");
        return ;
    }
    // 새로운 노드에 값 넣어주기?
    newNode -> data = x;
    newNode -> next = NULL;

    //기존(마지막 노드와 새로운 노드 연결)
    
    if (list-> head == NULL)
        list -> head = newNode;
    else{
        node* temp = list -> head;
        // 연결 리스트를 쭉 따라서 next가 비어있는 (NULL) 노드 찾기
        while (temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}


void printList(lkList* list){
    node* temp = list -> head;
    int i = 0;
    while (temp -> next != NULL){
        i++;
        printf("%d 번째 리스트속 데이터의 값 : %d\n",i,temp->data);
        temp = temp->next;
    }
    i++;
    printf("마지막 %d 번째 리스트속 데이터의 값 : %d\n",i,temp->data);

    return;
}

int main(){
    lkList LinkedList;
    LinkedList.head = NULL;

    nodeAppend(&LinkedList,3);
    nodeAppend(&LinkedList,4);
    nodeAppend(&LinkedList,5);
    nodeAppend(&LinkedList,6);
    nodeAppend(&LinkedList,7);
    printList(&LinkedList);

    return 0;
}

