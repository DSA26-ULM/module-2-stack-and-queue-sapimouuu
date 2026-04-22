#include <iostream>
#include <stdexcept>
#include "queue.h"

using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    // Sesuai batasan soal n <= 100 [cite: 52]
    int arr[105]; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (k <= 0 || k > n) return 0; // [cite: 53]

    Queue q;
    init(&q);

    long long currentSum = 0;
    try {
        for (int i = 0; i < k; i++) {
            enqueue(&q, arr[i]);
            currentSum += arr[i];
        }
        cout << currentSum;

        for (int i = k; i < n; i++) {
            int keluar = front(&q);
            dequeue(&q);
            
            enqueue(&q, arr[i]);
            currentSum = currentSum - keluar + arr[i];
            cout << " " << currentSum;
        }
        cout << endl;
    } catch (...) {
        return 0;
    }

    return 0;
}
