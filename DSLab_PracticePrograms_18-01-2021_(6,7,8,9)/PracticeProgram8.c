/*Develop an application (C Program) with suitable data structure to demonstrate the Online
Movie Ticket Reservation system, in which users request should get process on the basis of
First come First basis and display “Reservation Full”, “Reservation Started” appropriately
based on the availability of the Tickets.*/
#include<stdio.h>
#include<process.h>
#define QUE_SIZE 3
int item,front=0,rear=-1,q[10];
void insertrear()
{

    if(rear==QUE_SIZE-1)
    {
        printf("Reservation Full\n");
        return ;
    }
    rear=rear+1;
    q[rear]=item;
}
void displayQ()
{
    int i;
    if(front>rear)
    {
        printf("Reservation Started\n");
        return ;
    }
    printf("Reserved seat numbers\n");
    for(i=front;i<=rear;i++)
    {
        printf("%d\n",q[i]);
    }
}
void main()
{
    int choice;
    for(;;)
    {
        printf("\n1:Reserve ticket\n2:Display reserved seats\n3:Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the seat number\n");
            scanf("%d",&item);
            insertrear();
            break;
            case 2:displayQ();
            break;
            default:exit(0);
        }
    }
}

