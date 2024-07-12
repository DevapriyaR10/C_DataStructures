/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int a[10][10], i, j, n, choice, source, s[10];

void BFS(int a[10][10], int n, int source, int s[10]) {
    int q[10], u;
    int front = 1, rear = 1;
    s[source] = 1;
    q[rear] = source;
    while (front <= rear) {
        u = q[front];
        front += 1;
        for (i = 1; i <= n; i++) {
            if (a[u][i] == 1 && s[i] == 0) {
                rear += 1;
                q[rear] = i;
                s[i] = 1;
            }
        }
    }
}

int main() {
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    while (1) {
        printf("1. BFS\n2. Exit\n");
        printf("Enter the choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the source:");
                scanf("%d", &source);
                for (i = 1; i <= n; i++) {
                    s[i] = 0;
                }
                BFS(a, n, source, s);
                for (i = 1; i <= n; i++) {
                    if (s[i] == 0)
                        printf("The node %d is not reachable.\n", i);
                    else
                        printf("The node %d is reachable.\n", i);
                }
                break;
            case 2:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}
