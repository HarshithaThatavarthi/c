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
### 22. Define a union to represent the size of a product, which can be specified in centimeters, inches, or feet. Write a function to convert the size from one unit to another (e.g., centimeters to inches). 
```c

```
### 23. Define a structure to represent a date with day, month, and year (all integers). Write a function to check if a given year is a leap year. 
```c
#include <stdio.h>
struct date{
    int day;
    int month;
    int year;
};

void leap_year()
{
    struct date obj;
    printf("Enter day :");
    scanf("%d",&obj.day);
    printf("Enter the month :");
    scanf("%d",&obj.month);
    printf("Enter the year :");
    scanf("%d",&obj.year);
    check_leap_year(obj.day,obj.month,obj.year);
}

void check_leap_year(int day,int month,int year)
{
    if((year %4==0 && year % 100 !=0) || (year%400==0))
    {
        printf("The given %d - %d - %d is a leap year.",day,month,year);
    }
    else
    {
        printf("The given %d -%d - %d is not a leap year.",day,month,year);
    }
}

int main()
{
    leap_year();

    return 0;
}
```
### 24. Define a structure to represent a complex number with real and imaginary parts (both floats). Write a function to add two complex numbers represented by structures.
```c
#include<stdlib.h>
#include <stdio.h>
struct complex {
	int real;
	int imaginary;
};

void add_complex(struct complex number1,struct complex number2)
{
    int sum_real;
    int sum_imaginary;
    sum_real=number1.real+number2.real;
    sum_imaginary=number1.imaginary+number2.imaginary;
    if(sum_imaginary>=0){
        printf("The sum of two complex numbers is %d + i%d",sum_real,sum_imaginary);
    }
    else{
        printf("The sum of two complex numbers is %d - i%d",sum_real,abs(sum_imaginary));
    }
}


int main()
{
	struct complex number1;
	struct complex number2;
	printf("Enter the real part of complex number1: ");
	scanf("%d",&number1.real);
	printf("Enter the imaginary part of complex number1: ");
	scanf("%d",&number1.imaginary);
	printf("Enter the real part of complex number2: ");
	scanf("%d",&number2.real);
	printf("Enter the imaginary part of complex number2: ");
	scanf("%d",&number2.imaginary);
	add_complex(number1,number2);
	return 0;
}
```
### 25. Implement a linked list using structures. Each node in the list should hold an integer value and a pointer to the next node. 
```c
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node* head=NULL,*temp=NULL;
struct node *createNode(int value)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
int push(int value)
{
    struct node *newnode=createNode(value);
    if(head==NULL)
    {
        head=newnode;
        temp=head;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
}

void display()
{
    //struct node*head=NULL;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d   ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    return 0;
}
```
### 26. Define a self-referential structure to represent a binary tree node. Each node should have data (integer) and pointers to left and right child nodes. 
```c

```
