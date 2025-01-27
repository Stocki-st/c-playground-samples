#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (tolower(str[left]) != tolower(str[right])) {
            return 0; // Nicht ein Palindrom
        }
        left++;
        right--;
    }
    return 1; // Ist ein Palindrom
}

int main() {
    char str[100];
    printf("Geben Sie einen String ein: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Entfernen des Zeilenumbruchs
    if (isPalindrome(str)) {
        printf("'%s' ist ein Palindrom.\n", str);
    } else {
        printf("'%s' ist kein Palindrom.\n", str);
    }
    return 0;
}
