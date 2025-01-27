#include <stdio.h>

void fibonacci(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci-Zahlen bis %d: ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int main() {
    int number;
    printf("Geben Sie eine Zahl ein: ");
    scanf("%d", &number);
    fibonacci(number);
    return 0;
}
