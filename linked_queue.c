#include <stdio.h>
#include <stdlib.h>

//리어로 삽입
//프론트에서 pop 

//노드 구조체
typedef struct Node {
    int data;
    struct Node* next;
} node;
// 큐 구조체
typedef struct linked_queue
{
    node* front;
    node* rear;
    int size;
} que;

que* createQue(){
    que *q = malloc(sizeof(que));
    if (q==NULL){
        printf("memory fail");
        exit(EXIT_FAILURE);

    }
    q -> front = NULL;
    q -> rear = NULL;
    q -> size = 0;

    return q;
}

int isempty(que* q){
    return q-> front == NULL || q-> rear == NULL;
}

/* int isfull(){
    선형 큐니까 생략할게요
}*/

node* createNode(){
    node* n = malloc(sizeof(node));
    if (n == NULL){
        printf("memoryfail!");
        exit(0);
    }
    n -> data = 0;
    n -> next = NULL;

    return n;
}

void enqueue(que* q, int x){
    node* new = createNode();
    if (q-> size == 0){
        q -> front = new;
        q -> rear = new;
        new -> data = x;
        q->size++;
        return;
    }
    // 기존 리어 잠시 저장
    node* temp = q -> rear;
    q->rear = new;
    // 새로운 노드 데이터에 x저장
    new -> data = x;
    //기존 노드와 새로운 노드 연결
    temp -> next = new;
    q-> size++;
    return;
    
}

void dequeue(que* q, int *x){
    if (q->size ==0){
        printf("empty que\n");
        return;
    }
    // 프론트가 가리키는 노드에 접근
    node* temp = q -> front;
    // x에 기존 데이터 저장
    *x = temp -> data;
    //이젠 프론트는 기존의 다음에 해당하는 노드를 가리킴
    q-> front = temp -> next;
    // 기존 친구는 빠빠이
    free(temp);
    q-> size --;
}

void peek(que *q){
    if (q->size ==0){
        printf("empty que\n");
        return;
    }
    printf("front value: %d",q->front->data);
}

// 메인함수는 챗지피티


int main() {
    que* q = createQue();
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n");
        printf("Choose an operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                printf("%d has been added to the queue.\n", value);
                break;
            case 2:
                if (isempty(q)) {
                    printf("The queue is empty.\n");
                } else {
                    dequeue(q, &value);
                    printf("%d has been removed from the queue.\n", value);
                }
                break;
            case 3:
                peek(q);
                break;
            case 4:
                printf("Exiting the program.\n");
                // Additional tasks like memory deallocation can be performed here if needed
                return 0;
            default:
                printf("Invalid input. Please choose again.\n");
        }
    }

    return 0;
}
