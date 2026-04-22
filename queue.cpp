#include "queue.h"
#include <iostream>
#include <stdexcept> // Diperlukan untuk throw runtime_error

using namespace std;

// Inisialisasi antrean
void init(Queue* q) {
    q->front = nullptr;
    q->rear = nullptr;
}

// Cek apakah antrean kosong
bool isEmpty(const Queue* q) {
    return q->front == nullptr;
}

// Cek apakah antrean penuh (untuk array statis linear)
bool isFull(const Queue* q) {
    if (q->rear == nullptr) return false;
    // Penuh jika rear sudah menunjuk ke elemen terakhir array (index MAX-1)
    return q->rear == &(q->data[MAX - 1]);
}

// Menambah elemen ke belakang antrean
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw runtime_error("Queue Overflow"); // Sesuai instruksi soal 
    }

    if (isEmpty(q)) {
        q->data[0] = value;
        q->front = &(q->data[0]);
        q->rear = &(q->data[0]);
    } else {
        q->rear++; // Geser pointer rear ke alamat memori berikutnya
        *(q->rear) = value;
    }
}

// Menghapus elemen dari depan antrean
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw runtime_error("Queue Underflow"); // Sesuai instruksi soal 
    }

    if (q->front == q->rear) {
        // Jika hanya ada satu elemen, setelah dihapus antrean menjadi kosong
        q->front = nullptr;
        q->rear = nullptr;
    } else {
        q->front++; // Geser pointer front ke elemen berikutnya
    }
}

// Mengambil nilai elemen terdepan
int front(const Queue* q) {
    if (isEmpty(q)) {
        throw runtime_error("Queue is Empty");
    }
    return *(q->front);
}

// Mengambil nilai elemen terakhir
int back(const Queue* q) {
    if (isEmpty(q)) {
        throw runtime_error("Queue is Empty");
    }
    return *(q->rear);
}
