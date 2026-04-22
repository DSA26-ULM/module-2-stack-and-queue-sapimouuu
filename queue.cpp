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
    // Pengecekan apakah rear sudah menunjuk ke index terakhir array data
    return q->rear == &(q->data[MAX - 1]);
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw runtime_error("Queue Overflow"); // Sesuai instruksi soal 
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
        throw runtime_error("Queue Underflow"); // Sesuai instruksi soal 
    }
    
    if (q->front == q->rear) {
        // Jika elemen terakhir, reset pointer ke nullptr
        q->front = nullptr;
        q->rear = nullptr;
    } else {
        q->front++;
    }
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        throw runtime_error("Queue is Empty");
    }
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw runtime_error("Queue is Empty");
    }
    return *(q->rear);
}
