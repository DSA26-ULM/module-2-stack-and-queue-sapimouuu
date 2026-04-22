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
    // Dianggap penuh jika rear sudah mencapai batas akhir array
    if (q->rear == nullptr) return false;
    return q->rear == &(q->data[MAX - 1]);
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw runtime_error("Queue Overflow"); [cite: 41]
    }

    if (isEmpty(q)) {
        // Elemen pertama
        q->data[0] = value;
        q->front = &(q->data[0]);
        q->rear = &(q->data[0]);
    } else {
        // Geser rear ke alamat berikutnya
        q->rear++;
        *(q->rear) = value;
    }
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw runtime_error("Queue Underflow"); [cite: 41]
    }

    if (q->front == q->rear) {
        // Jika tinggal 1 elemen, balikkan ke kondisi nullptr
        q->front = nullptr;
        q->rear = nullptr;
    } else {
        // Majukan pointer front
        q->front++;
    }
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        throw runtime_error("Queue is Empty"); [cite: 41]
    }
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw runtime_error("Queue is Empty"); [cite: 41]
    }
    return *(q->rear);
}
