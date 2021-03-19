#include<stdio.h>
#include<stdlib.h>
#define QUE_SIZE 20
int item,f1=0,f2=0,f=0,r1=-1,r2=-1,r=-1,q1[10],q2[10],q[20],count=0;
void insertrear()
{

    if(r==QUE_SIZE-1)
    {
        printf("Room full\n");
        return ;
    }
    q[++r]=item;
}
int deletefront()
{

    if(f>r)
    {
        f=0;
        r=-1;
        return -1;
    }
    return q[f++];
}
void displayroom1()
{
    int i;
    if(f1>r1)
    {
        printf("Room 1 empty\n");
        return ;
    }
    printf("People with the following card numbers are present in room1\n");
    for(i=f1;i<=r1;i++)
    {
        printf("%d\n",q1[i]);
    }
}
int deleteroom1()
{

    if(f1>r1)
    {
        f1=0;
        r1=-1;
        return -1;
    }
    return q1[f1++];
}
int deleteroom2()
{

    if(f2>r2)
    {
        f2=0;
        r2=-1;
        return -1;
    }
    return q2[f2++];
}
void displayroom2()
{
    int i;
    if(f2>r2)
    {
        printf("Room 2 empty\n");
        return ;
    }
    printf("People with the following card numbers are present in room2\n");
    for(i=f2;i<=r2;i++)
    {
        printf("%d\n",q2[i]);
    }
}
void cal()
{
    if(f<r)
    {
        for(int i=f;i<=r;i++)
        {
            if(q[i]%2==0)
            {
                q1[++r1]=q[i];
                f++;
            }
            else
            {
                q2[++r2]=q[i];
                f++;
            }

        }
    }
    else
        return ;
}
void main()
{
    int choice;
    for(;;)
    {
        printf("\n1:Enter room\n2:Exit Room 1\n3:Exit Room 2\n4:Room 1 Card numbers\n5.Room 2 Card numbers\n6.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter Covid Test Room\n");
            printf("Your card number: %d\n",++count);
            item=count;
            insertrear();
            cal();
            break;
            case 2:printf("Exit room 1\n");
                item=deleteroom1();
            if(item==-1)
                printf("Room 1 is empty\n");
            else
                printf("Exit card number %d\n",item);
            break;
            case 3:printf("Exit room 2\n");
                item=deleteroom2();
            if(item==-1)
                printf("Room 2 is empty\n");
            else
                printf("Exit card number %d\n",item);
            break;
            /*case 4:printf("Exit room \n");
                item=deletefront();
            if(item==-1)
                printf("Room is empty\n");
            else
                printf("Exit card number %d\n",item);
            break;
            */
            case 4:printf("Room 1 card numbers\n");
            displayroom1();
            break;
            case 5:
                printf("Room 2 card numbers\n");
            displayroom2();
            break;
            case 6:exit(0);
            default:printf("Invalid choice\n");
        }
    }
}
