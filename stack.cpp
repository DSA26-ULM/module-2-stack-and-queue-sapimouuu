#include <iostream>
#include <stdexcept> // Diperlukan untuk runtime_error
#include "stack.h"

using namespace std;

// Inisialisasi stack
void init(Stack* s) {
    // top diset ke nullptr untuk menandakan stack kosong
    s->top = nullptr;
}

// Cek apakah stack kosong
bool isEmpty(const Stack* s) {
    return s->top == nullptr;
}

// Cek apakah stack penuh
bool isFull(const Stack* s) {
    if (s->top == nullptr) return false;
    // Penuh jika top menunjuk ke elemen terakhir array (index MAX-1)
    return s->top == &(s->data[MAX - 1]);
}

// Menambah elemen ke stack
void push(Stack* s, int value) {
    if (isFull(s)) {
        throw runtime_error("Stack Overflow"); // Exception handling 
    }

    if (isEmpty(s)) {
        s->top = &(s->data[0]); // Menunjuk elemen pertama
    } else {
        s->top++; // Geser pointer ke alamat memori berikutnya
    }
    *(s->top) = value;
}

// Menghapus elemen teratas
void pop(Stack* s) {
    if (isEmpty(s)) {
        throw runtime_error("Stack Underflow"); // Exception handling 
    }

    if (s->top == &(s->data[0])) {
        s->top = nullptr; // Jika elemen terakhir dihapus, set kembali ke nullptr
    } else {
        s->top--; // Geser pointer ke alamat sebelumnya
    }
}

// Melihat elemen teratas tanpa menghapus
int peek(const Stack* s) {
    if (isEmpty(s)) {
        throw runtime_error("Stack is Empty"); // Exception handling 
    }
    return *(s->top);
}
