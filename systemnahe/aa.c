#include<stdio.h>
#include <stdlib.h>

 struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Kuyruk boş!\n");
        return -1;
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    printf("Kuyruktan çıkarıldı: %d\n", value);
    return value;
}
