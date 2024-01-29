#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *rlink;
    struct node *llink;
    char data;
} node;

typedef struct deque{
    node* rear;
    node* front;
    int size;
} deque;

deque* create(){
    deque* dq = malloc(sizeof(deque));
    if (dq == NULL){
        printf("MEMEORY FAILURE");
        exit(EXIT_FAILURE);
    }
    dq -> front = NULL;
    dq -> rear = NULL;
    dq -> size = 0;
    return dq;
}

int is_empty(deque* dq){
    return dq -> front == NULL;
}

node * newnode(char data) {
    node * new = malloc(sizeof(node));
    if (new == NULL){
        printf("MEMEORY FAILURE");
        exit(EXIT_FAILURE);
    }
    new -> data = data;
    new -> rlink = NULL;
    new -> llink = NULL;
    return new;
}

void add_front(deque* dq, char data) {
    node* new = newnode(data);
    if (is_empty(dq)){
        dq -> front =  new;
        dq -> rear = new;
    }
    else{
        dq -> front -> llink = new;
        new -> rlink = dq -> front;
        dq -> front = new;
        
    }
    dq -> size++;
}

void add_rear(deque* dq, char data) {
    node* new = newnode(data);
    if (is_empty(dq)){
        dq -> front =  new;
        dq -> rear = new;
    }
    else{
        dq -> rear -> rlink = new;
        new -> llink = dq -> rear;
        dq -> rear = new;
    }
    dq -> size++;
}

char popFront(deque* dq){
    char result;
    if (is_empty(dq)){
        printf("empty\n");
        return '\0';
    }
    node *temp = dq -> front;
    dq -> front = temp -> rlink;
    temp -> rlink = NULL;
    result = temp->data;
    free(temp);
    
    if (dq->front != NULL) {
        dq -> front -> llink = NULL;
    } else {
        dq -> rear = NULL;  // 덱이 비어있을 때 rear도 NULL로 설정
    }

    dq -> size--;

    return result;
}

char popRear(deque* dq){
    char result;
    if (is_empty(dq)){
        printf("empty\n");
        return '\0';
    }
    node *temp = dq -> rear;
    dq -> rear = temp -> llink;
    temp -> llink = NULL;
    result = temp->data;
    free(temp);
    if (dq->rear != NULL) {
        dq -> rear -> rlink = NULL;
    } else {
        dq -> front = NULL;  // 덱이 비어있을 때 front도 NULL로 설정
    }
    dq -> size--;
    return result;
}


void printDeque(deque * dq){ // front 부터 rear까지 순서대로 출력
    if(is_empty(dq)) {
        printf("empty deque");
        return;
        }
    node* temp = dq -> front;
    printf("front\n");
    while (temp !=NULL){
        printf("data: %c\n",temp -> data);
        temp = temp -> rlink;
    }
    printf("rear\n");
    return;
}

char get_front(deque *dq){
    return dq -> front -> data;
}
char get_rear(deque *dq){
    return dq -> rear -> data;
}


void destroyDeque(deque* dq) {
    while (!is_empty(dq)) {
        popFront(dq);
    }
    free(dq);
}

int get_size(deque*dq){
    return dq -> size;
}



int main() {
    deque* myDeque = create(); // 덱 생성

    int choice;
    char data;

    do {
        // 사용자에게 가능한 명령을 안내
        printf("\nChoose an option:\n");
        printf("1. Add element to the front\n");
        printf("2. Add element to the rear\n");
        printf("3. Pop element from the front\n");
        printf("4. Pop element from the rear\n");
        printf("5. Print the deque\n");
        printf("6. Get front element\n");
        printf("7. Get rear element\n");
        printf("8. Get size of the deque\n");
        printf("0. Exit\n");

        // 사용자의 선택을 읽기
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add to the front: ");
                scanf(" %c", &data);
                add_front(myDeque, data);
                break;
            case 2:
                printf("Enter data to add to the rear: ");
                scanf(" %c", &data);
                add_rear(myDeque, data);
                break;
            case 3:
                printf("Popped from front: %c\n", popFront(myDeque));
                break;
            case 4:
                printf("Popped from rear: %c\n", popRear(myDeque));
                break;
            case 5:
                printf("Deque:\n");
                printDeque(myDeque);
                break;
            case 6:
                printf("Front of the deque: %c\n", get_front(myDeque));
                break;
            case 7:
                printf("Rear of the deque: %c\n", get_rear(myDeque));
                break;
            case 8:
                printf("Size of the deque: %d\n", get_size(myDeque));
                break;
            case 0:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    // 덱 해제
    destroyDeque(myDeque);

    return 0;
}
