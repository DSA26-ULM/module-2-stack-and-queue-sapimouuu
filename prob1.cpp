#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main() {
    Stack s;
    init(&s);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string simbol;
        cin >> simbol;

        if (simbol == "+" || simbol == "-" || simbol == "*" || simbol == "/") {
            int bil2 = peek(&s); pop(&s);
            int bil1 = peek(&s); pop(&s);

            if (simbol == "+") push(&s, bil1 + bil2);
            else if (simbol == "-") push(&s, bil1 - bil2);
            else if (simbol == "*") push(&s, bil1 * bil2);
            else if (simbol == "/") push(&s, bil1 / bil2);
        } 
        else {
            int angka = stoi(simbol);
            push(&s, angka);
        }
    }

    cout << peek(&s) << endl;

    return 0;
}
