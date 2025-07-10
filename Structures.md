# C Programming
## Structures & Unions
### 18. Create a structure to represent a student with the following members: name (string), roll number(int), and marks (float). Write a function to display the details of a student. 
```c
    #include <stdio.h>

struct student{
    char name[50];
    int rollno;
    float marks;
};

void display(char* name,int rollno,float marks)
{
    printf("Student name is : %s \n",name);
    printf("Student Rollno is : %d \n",rollno);
    printf("Student Marks : %f \n",marks);
}

int main()
{
    struct student st;
    printf("Enter student name: ");
    fgets(st.name,sizeof(st.name),stdin);
    printf("Enter Roll no: ");
    scanf("%d",&st.rollno);
    printf("Enter Marks: ");
    scanf("%f",&st.marks);
    display(st.name,st.rollno,st.marks);
    return 0;
}
```
### 19.Define a union to store either an integer or a floatingpoint number. Write a function to accept the type of data (integer or float) and then read the corresponding value from the user. Store the value in the union and print it. 
```c
#include<stdio.h>

union store{
    int i;
    float f;
};

void read_value()
{
    union store u;
    int choice;
    printf("Types of data: ");
    printf("1. Integer\n");
    printf("2. Float\n");
    printf("Enter Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            printf("Enter integer value: ");
            scanf("%d",&u.i);
            printf("You entered integer: %d",u.i);
            break;
        }
        case 2:
        {
            printf("Enter float value: ");
            scanf("%f",&u.f);
            printf("You entered float: %.2f",u.f);
            break;
        }
        default:
        {
            printf("Invalid choice");
        }
    }
}

int main()
{
    read_value();
    return 0;
}
```
### 20. Define a structure to represent a point in 2D space with x and y coordinates (both integers). Write a function to check if two points are equal (have the same x and y coordinates). 
```c
#include <stdio.h>

struct point{
    int x;
    int y;
};

void equality_check(struct point p1,struct point p2)
{
    if((p1.x==p2.x) && (p1.y==p2.y)) 
    {
        printf("Point coordinates are eqaul");
    }
    else{
         printf("Point coordinates are not eqaul");
    }
}

int main()
{
    struct point p1,p2;
    printf("Enter point1: ");
    scanf("%d %d",&p1.x,&p1.y);
    printf("Enter point2: ");
    scanf("%d %d",&p2.x,&p2.y);
    equality_check(p1,p2);
    return 0;
}
```
### 21. Create a structure to represent a book with the following members: title (string), author (string), ISBN (long int), and number of pages (int). Write a function to accept details of a book from the user and store them in a structure variable. 
```c
#include <stdio.h>

struct book{
    char title[50];
    char author[50];
    long int ISBN;
    int number_of_pages;
};

void book_details()
{
    struct book b;
    printf("Enter book title: ");
    fgets(b.title,sizeof(b.title),stdin);
    printf("Enter Author name: ");
    fgets(b.author,sizeof(b.author),stdin);
    printf("Enter ISBN: ");
    scanf("%ld",&b.ISBN);
    printf("Enter number of pages: ");
    scanf("%d",&b.number_of_pages);
    printf("Book title is: %s",b.title);
    printf("Author name is: %s",b.author);
    printf("ISBN is: %ld",b.ISBN);
    printf("Number of pages: %d",b.number_of_pages);
}

int main()
{
    book_details();
    return 0;
}
```
