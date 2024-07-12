#include <stdio.h>
#include <string.h>

void stringMatch(char str[], char pat[], char rep[], char ans[]) {
    int i = 0, c = 0, m = 0, k, j = 0, flag = 0;

    while (str[c] != '\0') {
        if (str[c] == pat[i]) {
            i++;
            if (pat[i] == '\0') {
                flag = 1;
                for (k = 0; rep[k] != '\0'; k++, j++) {
                    ans[j] = rep[k];
                }
                i = 0;
            }
        } else {
            ans[j] = str[c];
            i = 0;
            j++;
        }
        c++;
    }

    ans[j] = '\0';  // Add null terminator

    if (flag == 1) {
        printf("The result string: %s\n", ans);
    } else {
        printf("The pattern is not found.\n");
    }
}

int main() {
    char str[100], pat[100], rep[100], ans[100];

    printf("String: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove the newline character

    printf("Pattern: ");
    fgets(pat, sizeof(pat), stdin);
    pat[strcspn(pat, "\n")] = '\0';

    printf("Replacement: ");
    fgets(rep, sizeof(rep), stdin);
    rep[strcspn(rep, "\n")] = '\0';

    stringMatch(str, pat, rep, ans);

    return 0;
}
