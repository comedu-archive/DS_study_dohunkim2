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
    return q-> front == NULL;
}

/* int isfull(){
    선형 큐니까 생략할게요
}*/

node* createNode(int x){
    node* n = malloc(sizeof(node));
    if (n == NULL){
        printf("memoryfail!");
        exit(EXIT_FAILURE);
    }
    n -> data = x;
    n -> next = NULL;

    return n;
}

void enqueue(que* q, int x){
    node* new = createNode(x);
    if (isempty(q)){
        q -> front = new;
        q -> rear = new;
        new -> data = x;
        q->size++;
        return;
    }
    // 새로운 노드 데이터에 x저장
    new -> data = x;
    //기존 노드와 새로운 노드 연결
    q -> rear -> next = new;
    q -> rear = new;
    q-> size++;
    return;
    
}

void dequeue(que* q, int *x){
    if (isempty(q)){
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
    
    if (isempty(q)){
        q-> front = NULL; 
        q-> rear = NULL;
    }
}

void peek(que *q, int* x){
    if (isempty(q)){
        printf("empty que\n");
        return;
    }
    *x = q -> front -> data;
}

int get_size(que *q){
    return q -> size;
}

int is_member(que *q, int x){
    node* temp = q -> front;
    while(temp -> next != NULL){
        if (temp -> data == x){
            return 1;
            temp = temp -> next;
        }
        return -1;
    }
}

// 메인함수는 챗지피티
int main() {
    // Create a queue
    que* myQueue = createQue();

    int choice, value;
    
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check Membership\n");
        printf("5. Get Queue Size\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(myQueue, value);
                printf("Enqueued %d\n", value);
                break;
            
            case 2:
                if (!isempty(myQueue)) {
                    dequeue(myQueue, &value);
                    printf("Dequeued value: %d\n", value);
                } else {
                    printf("Queue is empty. Cannot dequeue.\n");
                }
                break;

            case 3:
                if (!isempty(myQueue)) {
                    peek(myQueue, &value);
                    printf("Front value: %d\n", value);
                } else {
                    printf("Queue is empty. Cannot peek.\n");
                }
                break;

            case 4:
                printf("Enter value to check membership: ");
                scanf("%d", &value);
                if (is_member(myQueue, value) == 1) {
                    printf("%d is a member of the queue.\n", value);
                } else {
                    printf("%d is not found in the queue.\n", value);
                }
                break;

            case 5:
                printf("Queue size: %d\n", get_size(myQueue));
                break;

            case 6:
                // Clean up and exit
                free(myQueue);
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
