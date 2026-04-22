#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (k <= 0 || k > n) return 0;

    Queue q;
    init(&q);

    long long currentSum = 0;
    for (int i = 0; i < k; i++) {
        enqueue(&q, arr[i]);
        currentSum += arr[i];
    }

    cout << currentSum;

    for (int i = k; i < n; i++) {
        int keluar = front(&q);
        dequeue(&q);

        int masuk = arr[i];
        enqueue(&q, masuk);

        currentSum = currentSum - keluar + masuk;

        cout << " " << currentSum;
    }

    cout << endl;

    return 0;
}
