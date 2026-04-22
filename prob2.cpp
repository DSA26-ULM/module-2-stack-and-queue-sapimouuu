#include <iostream>
#include <stdexcept> // Tambahkan ini untuk handle throw
#include "queue.h"

using namespace std;

int main() {
    int n, k;
    // Gunakan MAX dari queue.h agar sinkron
    if (!(cin >> n >> k)) return 0;

    // Batasan soal: 1 <= n <= 100, 1 <= k <= n 
    if (n <= 0 || k <= 0 || k > n) return 0;

    int arr[101]; // Sesuai batasan n <= 100 [cite: 52]
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Queue q;
    init(&q);

    long long currentSum = 0;

    try {
        // Isi jendela pertama [cite: 47]
        for (int i = 0; i < k; i++) {
            enqueue(&q, arr[i]);
            currentSum += arr[i];
        }

        cout << currentSum;

        // Geser jendela (Sliding Window) [cite: 48]
        for (int i = k; i < n; i++) {
            int keluar = front(&q);
            dequeue(&q);

            int masuk = arr[i];
            enqueue(&q, masuk);

            currentSum = currentSum - (long long)keluar + masuk;
            cout << " " << currentSum;
        }
        cout << endl;
    } catch (...) {
        // Jika terjadi error dari queue (seperti overflow), program tidak crash
        return 0;
    }

    return 0;
}
