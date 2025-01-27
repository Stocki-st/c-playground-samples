#include <stdio.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int number;
    printf("Geben Sie eine Zahl ein: ");
    scanf("%d", &number);
    printf("Primzahlen bis %d: ", number);
    for (int i = 2; i <= number; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
