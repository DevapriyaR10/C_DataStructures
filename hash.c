#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define mod(x) (x % MAX)

void linear_prob(int a[], int num, int key) {
    if (a[key] == -1) {
        a[key] = num;
    } else {
        printf("\nCollision detected\n");
        int i;
        for (i = mod(key + 1); i != key; i = mod(i + 1)) {
            if (a[i] == -1) {
                printf("\nCollision avoided successfully\n");
                a[i] = num;
                return;
            }
            else
            printf("The hash table is full\n");
        }
    }
}

void display(int a[]) {
    int i, ch;
    printf("1. Filtered display\n2. Display all\n");
    printf("Enter your choice:");
    scanf("%d", &ch);
    for (i = 0; i < MAX; i++) {
        if (a[i] != -1 || ch == 2)
            printf("%d %d\n", i, a[i]);
    }
}

int main() {
    int a[MAX], num, i;
    printf("\nCollision handling by linear probing\n");
    for (i = 0; i < MAX; i++) {
        a[i] = -1;
    }
    do {
        printf("\nEnter the data:");
        scanf("%d", &num);
        linear_prob(a, num, mod(num));
        printf("Do you want to continue(0/1):");
        scanf("%d", &i);
    } while (i == 1);
    display(a);
    return 0;
}
