#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top; 
};


struct Queue {
    struct Node* front; 
    struct Node* rear; 
};

struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->data = value;
    node->next = NULL;
    return node;
}


struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

int isEmptyStack(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    int poppedValue = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmptyQueue(struct Queue* queue) {
    return queue->front == NULL;
}

void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = createNode(value);
    if (isEmptyQueue(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}


int dequeue(struct Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue underflow!\n");
        exit(1);
    }
    int dequeuedValue = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return dequeuedValue;
}

int main() {
    struct Stack* stack = createStack();
    printf("Pushing elements onto the stack:\n");
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("Popping elements from the stack:\n");
    while (!isEmptyStack(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");

    struct Queue* queue = createQueue();
    printf("Enqueuing elements into the queue:\n");
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("Dequeuing elements from the queue:\n");
    while (!isEmptyQueue(queue)) {
        printf("%d ", dequeue(queue));
    }
    printf("\n");

    return 0;
}
