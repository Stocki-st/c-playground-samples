#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 256

void countCharacterFrequency(char str[]) {
    int count[ASCII_SIZE] = {0};
    for (int i = 0; str[i]; i++) {
        count[(unsigned char)str[i]]++;
    }

    printf("Häufigkeit der Zeichen:\n");
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (count[i] > 0) {
            printf("'%c' : %d\n", i, count[i]);
        }
    }
}

int main() {
    char str[100];
    printf("Geben Sie einen String ein: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Entfernen des Zeilenumbruchs
    countCharacterFrequency(str);
    return 0;
}
