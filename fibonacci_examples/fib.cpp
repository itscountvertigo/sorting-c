/*
    Basic scipt that generates Fibonacci numbers to explain C++ Syntax
*/

#include<iostream>
using namespace std;

void fibonacci(int max) {
    int a = 0, b = 1, c;

    cout << "0\n1\n";

    for (int i = 2; i < max; i++) {
        c = a + b;
        a = b;
        b = c;

        cout << c << "\n";
    }
}

int main() {
    fibonacci(22);
}
