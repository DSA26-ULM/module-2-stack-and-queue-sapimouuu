#include "queue.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void init(Queue* q) {
    q->front = nullptr;
    q->rear = nullptr;
}

bool isEmpty(const Queue* q) {
    return q->front == nullptr;
}

bool isFull(const Queue* q) {
    if (isEmpty(q)) return false;
    // Penuh jika rear sudah menunjuk elemen terakhir di MAX (100)
    return q->rear == &(q->data[MAX - 1]);
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw runtime_error("Queue Overflow"); // Syarat soal 3 [cite: 41]
    }
    if (isEmpty(q)) {
        q->data[0] = value;
        q->front = &(q->data[0]);
        q->rear = &(q->data[0]);
    } else {
        q->rear++;
        *(q->rear) = value;
    }
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw runtime_error("Queue Underflow"); // Syarat soal 3 [cite: 41]
    }
    if (q->front == q->rear) {
        q->front = nullptr;
        q->rear = nullptr;
    } else {
        q->front++; // Cukup majukan front saja
    }
}

int front(const Queue* q) {
    if (isEmpty(q)) throw runtime_error("Queue is Empty");
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) throw runtime_error("Queue is Empty");
    return *(q->rear);
}
