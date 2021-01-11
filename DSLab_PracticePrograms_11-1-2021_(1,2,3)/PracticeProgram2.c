/*2. An Application is to be developed to manage the records of the candidates who register for
the NPTEL online course. The NPTEL has planned to conduct the course for 250 candidates
on First Come First Serve course registration basis. Once all the 250 candidates are registered
the message should be displayed as “Registration Closed” and no student is allowed to leave
the course until the completion. Identify the suitable data structure and develop an
application(C Program) for the above scenario.*/
#include<stdio.h>
#include<process.h>
#define QUE_SIZE 250
int item;int front=0,rear=-1;
int q[250];
void insertrear()
{

    if(rear==QUE_SIZE-1)
    {
        printf("Registration Closed\n");
        return ;
    }
    rear=rear+1;
    q[rear]=item;
    printf("Registered successfully\n");
}
void displayQ()
{
    int i;
    if(front>rear)
    {
        printf("No registrations yet\n");
        return ;
    }
    printf("Details(Roll numbers) of registered students:\n");
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
        printf("\n1:Register now\n2:Details of registered students\n3:Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter your roll number\n");
            scanf("%d",&item);
            insertrear();
            break;
            case 2:displayQ();
            break;
            case 3:exit(0);
            default:printf("Invalid choice\n");
        }
    }
}
