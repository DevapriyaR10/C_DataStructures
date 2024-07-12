/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node{
    char eid[10];
    char ename[10];
    char dept[10];
    char desig[10];
    int sal;
    long int phone;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE first=NULL;
int count=0;

NODE create(){
    NODE enode;
    enode=(NODE)malloc(sizeof(struct node));
    if(enode==NULL){
        printf("Memory is not sufficient");
        exit(1);
    }
    printf("Enter the employee ID, Name, Department, Designation, Salary, Phone number:\n");
    scanf("%s\n%s\n%s\n%s\n%d\n%ld", enode->eid, enode->ename, enode->dept, enode->desig, &enode->sal, &enode->phone);
    enode->llink=NULL;
    enode->rlink=NULL;
    count++;
    return enode;
}

NODE insertfront(){
    NODE temp;
    temp=create();
    if(first==NULL){
        return temp;
    }
    temp->rlink=first;
    first->llink=temp;
    return temp;
}

NODE deletefront(){
    NODE temp;
    if(first==NULL){
        printf("The list is empty\n");
        return NULL;
    }
    if(first->rlink==NULL){
        printf("The details of employee with id %s were deleted\n", first->eid);
        free(first);
        count--;
        return NULL;
    }
    temp=first;
    first=first->rlink;
    temp->rlink=NULL;
    first->llink=NULL;
    printf("The details of employee with id %s were deleted\n", temp->eid);
    free(temp);
    count--;
    return first;
    }
    
    NODE insertend(){
        NODE temp, cur;
        temp=create();
        if(first==NULL){
            first=temp;
            return NULL;
        }
        cur=first;
        while(cur->rlink!=NULL){
            cur=cur->rlink;
        }
        cur->rlink=temp;
        temp->llink=cur;
        return first;
    }
    
    NODE deleteend(){
        NODE cur, prev;
        if(first==NULL){
            printf("The list is empty");
            return NULL;
        }
        cur=first;
        prev=NULL;
        while(cur->rlink!=NULL){
            prev=cur;
            cur=cur->rlink;
        }
        if(first->rlink==NULL){
        printf("The details of employee with id %s were deleted\n", first->eid);
        free(first);
        count--;
        return NULL;
        }
        printf("The details of employee with id %s were deleted\n", cur->eid);
        cur->llink=NULL;
        prev->rlink=NULL;
        free(cur);
        count--;
        return first;
    }
    
    void display(){
        NODE cur;
        if(first==NULL){
            printf("The list is empty\n");
        }
        cur=first;
        while(cur!=NULL){
            printf("ID| %s Name| %s Department| %s Designation| %s Salary| %d Phone| %ld\n", cur->eid, cur->ename, cur->dept, cur->desig, cur->sal, cur->phone);
            cur=cur->rlink;
        }
    }
    
    void main(){
        int i, ch, n;
        while(1){
            printf("Menu\n");
            printf("1.Insert at front\n");
            printf("2. Delete at front\n");
            printf("3. Insert at end\n");
            printf("4. Delete at end\n");
            printf("5. Display\n");
            printf("6. Exit\n");
            printf("Enter your choice:");
            scanf("%d", &ch);
            switch(ch){
                case 1: printf("Enter the number of employees:");
                        scanf("%d", &n);
                        for(i=0; i<n; i++){
                            first=insertfront();
                        }
                        break;
                case 2: first=deletefront();
                        break;
                case 3: first= insertend();
                        break;
                case 4: first=deleteend();
                        break;
                case 5: display();
                        break;
                case 6: exit(0);
                        break;
                default: printf("Invalid input\n");
            }
        }
    }

