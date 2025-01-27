#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main() {
    char str[100];
    printf("Geben Sie einen String ein: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Entfernen des Zeilenumbruchs
    reverseString(str);
    printf("Umgekehrter String: %s\n", str);
    return 0;
}
