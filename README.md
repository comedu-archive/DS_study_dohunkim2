링크드 큐 int 형으로 코딩했어요 
죄송합니다 교수님


# 태수의 답변

- `void*`를 이용하는 방식은 메모리에 대한 깊은 이해를 요구하기에 쉽지 않으니 요구사항은 아님, ㄱㅊ


# 피드백

## createNode
```c++
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
```
- 0을 반환하는 행위는 주로 프로그램이 정상적으로 끝남을 의미하므로, 심각한 오류에 대한 예외 처리는 EXIT_FAILURE 로 통일하길 바람
- 혹은 개발자가 원하는 숫자로 직접 에러 코드를 정할 수도 있겠지
- node 구조체 변수를 세팅하는 김에 아예 data 값도 매개변수로 가져와서 대입했으면 더 깔끔했을 듯



## isempty
```c++
int isempty(que* q){
    return q-> front == NULL || q-> rear == NULL;
}
```

- queue의 특성상 `q->front`가 NULL이라면 `q->back` 또한 NULL일 것임을 알 수 있음, 둘은 같은 연결리스트를 가리키니까 말이지.
- 그러므로 둘 중 하나만 확인해도 큰 상관이 없음
- 만약 더욱 안전한 코드를 만들고 싶었다면, 매개변수로 받아온 `q`가 NULL인지 확인하는 편이 나았을 것이다. 
- 그리고 이 코드는 dequeue 함수의 구현 방식으로 인해 무용지물이 되었는데, 이는 아래에 설명하겠음


## enqueue

```c++
void enqueue(que* q, int x){
    node* new_ = createNode();
    if (q-> size == 0){
        q -> front = new_;
        q -> rear = new_;
        new_ -> data = x;
        q->size++;
        return;
    }
    node* temp = q -> rear;
    q->rear = new_;
    new_ -> data = x;
    temp -> next = new_;
    q-> size++;
    return;
    
}
```

- `temp`를 사용하는 것보다 아예 `q -> rear -> next = new_;` 이렇게 직접적으로 대입해주는 것도 좋겠다.
- 이 코드에서는 큐가 비어있는지를 `q-> size == 0`을 통해 확인했는데, 위에 정의해 둔 `isempty`를 사용하는 것이 더욱 깔끔하지 않았을까?



## dequeue

```c++
void dequeue(que* q, int *x){
    if (q->size ==0){
        printf("empty que\n");
        return;
    }
    node* temp = q -> front;
    *x = temp -> data;
    q-> front = temp -> next;
    free(temp);
    q-> size --;
}
```

- 값을 삭제한 뒤, 연결리스트에 값이 더이상 존재하지 않는다면, `q->front`와 `q->rear`가 가리키는 메모리는 어떤 메모리일까?
- `q->front`와 `q->rear`은 이제 가리킬 연결 리스트가 없으니, 다시 NULL로 초기화 해주어야 하지 않을까?
- 이 과정이 없으면, 이후의 큐 사용에서 버그가 생길 수 있으며, 무엇보다 `isempty` 함수의 정상작동이 보장되지 않는다.


```c++
void peek(que *q){
    if (q->size ==0){
        printf("empty que\n");
        return;
    }
    printf("front value: %d",q->front->data);
}
```

- `printf`함수를 쓰는 것보다 `q->front->data`에 해당하는 값을 함수의 사용자에게 넘겨주는 방식이 더욱 활용하기 좋을 것이다.
- `return`문을 사용할 수도 있고, `dequeue` 함수에서 썼던 것처럼 포인터를 이용할 수도 있을 것이다.



그리고, 다른 기능들 어디감?

적어도 size정도까진 만드셈







