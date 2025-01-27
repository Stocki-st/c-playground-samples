#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    int number;
    printf("Geben Sie eine Zahl ein: ");
    scanf("%d", &number);
    printf("Die Fakultät von %d ist %llu\n", number, factorial(number));
    return 0;
}
