#include <stdio.h>
#include <string.h>

int main() {
    char s[200];

    printf("Enter assembly instruction: ");
    if (fgets(s, sizeof(s), stdin) == NULL) return 0;

    if (strstr(s, "MACRO") != NULL) {
        printf("It is a macro definition\n");
    } else {
        printf("It is not a macro definition\n");
    }

    return 0;
}
