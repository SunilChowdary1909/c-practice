#include <stdio.h>
void fibonacci(int n) {
    int a = 0, b = 1, next;
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
}
int main() {
    int n = 10;  // Display first 10 Fibonacci numbers
    fibonacci(n);
    return 0;
}
