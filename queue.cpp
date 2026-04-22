#include "queue.h"
#include <iostream>

void init(Queue* q) {
    q->front = nullptr;
    q->rear = nullptr;
}

bool isEmpty(const Queue* q) {
    return q->front == nullptr;
}

bool isFull(const Queue* q) {
    if (q->rear == nullptr) return false;
    return (q->rear - q->data) == MAX - 1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) return;

    if (isEmpty(q)) {
        q->data[0] = value;
        q->front = &q->data[0];
        q->rear = &q->data[0];
    } else {
        q->rear++;
        *(q->rear) = value;
    }
}

void dequeue(Queue* q) {
    if (isEmpty(q)) return;

    if (q->front == q->rear) {
        q->front = nullptr;
        q->rear = nullptr;
    } else {
        q->front++;
    }
}

int front(const Queue* q) {
    return *(q->front);
}

int back(const Queue* q) {
    return *(q->rear);
}
