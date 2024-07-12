/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DAYS 7
int i;
// Structure to represent a day of the week
struct Day {
char *name; int date;
char *activity;
};

// Function to create the calendar
struct Day* create()
{
struct Day *calendar;
calendar = (struct Day*)malloc(MAX_DAYS * sizeof(struct Day));
if(calendar==NULL)
{
printf("Insufficient Memory\n");
exit(0);
}
return calendar;
}

void read(struct Day *calendar)
{
for (i = 0; i < MAX_DAYS; i++)
{
calendar[i].name = (char *)malloc(20 * sizeof(char));
// Assuming max day name length of 20 characters
printf("Enter the name of day %d: ", i + 1);
scanf("%s", calendar[i].name);
printf("Enter the date of %s: ", calendar[i].name);
scanf("%d", &calendar[i].date);
calendar[i].activity = (char *)malloc(100 * sizeof(char));
// Assuming max activity description length of 100 characters
printf("Enter the activity for %s: ", calendar[i].name);
scanf(" %s", calendar[i].activity);
}
}

// Function to display the calendar
void display(struct Day *calendar)
{
printf("\nDay\t\tDate\t\tActivity\n");
for (i = 0; i < MAX_DAYS; i++) {
printf("%s\t\t\t%d\t\t\t%s\n", calendar[i].name, calendar[i].date, calendar[i].activity);
}
}
int main() {
struct Day *calendar=create();
// Read the calendar
read(calendar);
// Display the calendar
display(calendar);
// Clean up dynamically allocated memory
for (int i = 0; i < MAX_DAYS; i++)
{
free(calendar[i].name);
free(calendar[i].activity);
}
return 0;
}
