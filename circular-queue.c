#include <stdio.h>
#include <stdlib.h>

#define MAX 5

char cq[MAX];
int front = -1, rear = -1;

void insert(char item);
void delete();
void display();

int main() {
    int choice;
    char item;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Element to insert: ");
                scanf(" %c", &item);
                insert(item);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void insert(char item) {
    if ((front == 0 && rear == MAX - 1) || front == (rear + 1) % MAX) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        cq[rear] = item;
        printf("Element %c inserted successfully\n", item);
    }
}

void delete() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        char element = cq[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        printf("Element %c deleted successfully\n", element);
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Circular Queue elements:\n");

        for (int i = front; i != (rear + 1) % MAX; i = (i + 1) % MAX) {
            printf("%c\n", cq[i]);
        }
    }
}

