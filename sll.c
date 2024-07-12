/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node {
    char usn[20];
    char name[50];
    char branch[10];
    int sem;
    long int phone;
    struct node *link;
};

typedef struct node *NODE;
NODE start = NULL;
int count = 0;

NODE create() {
    NODE snode;
    snode = (NODE)malloc(sizeof(struct node));
    if (snode == NULL) {
        printf("Memory is insufficient");
        exit(1);
    }
    printf("Enter the USN, Name, Branch, Sem and Phone number of students:\n");
    scanf("%s %s %s %d %ld", snode->usn, snode->name, snode->branch, &snode->sem, &snode->phone);
    snode->link = NULL;
    count++;
    return snode;
}

NODE insertfront() {
    NODE temp;
    temp = create();
    if (start == NULL) {
        return temp;
    }
    temp->link = start;
    return temp;
}

NODE deletefront() {
    NODE temp;
    if (start == NULL) {
        printf("The list is empty");
        return NULL;
    }
    if(start->link==NULL){
        printf("The student details with usn %s is deleted", start->usn);
        free(start);
        count--;
        return NULL;
    }
    temp = start;
    start = start->link;
    printf("The student details with usn %s is deleted", temp->usn);
    free(temp);
    count--;
    return start;
    
}

NODE insertend() {
    NODE cur, temp;
    temp = create();
    if (start == NULL) {
        return temp;
    }
    cur = start;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
    return start;
}

NODE deletend() {
    NODE cur, prev;
    if (start == NULL) {
        printf("The list is empty");
        return NULL;
    }
    if (start->link == NULL) {
        printf("The student details with usn %s is deleted", start->usn);
        free(start);
        count--;
        return NULL;
    }
    cur = start;
    while (cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }
    printf("The student details with usn %s is deleted", cur->usn);
    free(cur);
    prev->link = NULL;
    count--;
    return start;
}

void display() {
    NODE cur;
    if (start == NULL) {
        printf("The list is empty");
        return;
    }
    printf("The contents of list are:\n");
    cur = start;
    while (cur != NULL) {
        printf("USN: %s | Name: %s | Branch: %s | Sem: %d | Phone no: %ld\n", cur->usn, cur->name, cur->branch, cur->sem, cur->phone);
        cur = cur->link;
    }
    printf("The number of students are %d", count);
}

int main() {
    int ch, n;
    while (1) {
        printf("\nMENU\n");
        printf("1. Insert at front\n");
        printf("2. Delete at front\n");
        printf("3. Insert end\n");
        printf("4. Delete end\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the number of students:");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    start=insertfront();
                }
                break;
            case 2:
                start=deletefront();
                break;
            case 3:
                start=insertend();
                break;
            case 4:
                start=deletend();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Enter valid input!");
        }
    }
    return 0;
}


