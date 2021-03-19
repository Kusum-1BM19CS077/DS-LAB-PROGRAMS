#include<stdio.h>
#include<stdlib.h>
#define QUE_SIZE 10
int item1,f1=0,f2=0,f=0,r1=-1,r2=-1,r=-1,q1[10];char q2[10],q[20];
char item2;
void insertrear1()
{

    if(r1==QUE_SIZE-1)
    {
        printf("Queue 1 overflow\n");
        return ;
    }
    r1=r1+1;
    q1[r1]=item1;
}
void insertrear2()
{

    if(r2==QUE_SIZE-1)
    {
        printf("Queue 2 overflow\n");
        return ;
    }
    r2=r2+1;
    q2[r2]=item2;
}
int deletefront1()
{

    if(f1>r1)
    {
        f1=0;
        r1=-1;
        return -1;
    }
    return q1[f1++];
}
char deletefront2()
{

    if(f2>r2)
    {
        f2=0;
        r2=-1;
        return '*';
    }
    return q2[f2++];
}
void displayQ1()
{
    int i;
    if(f1>r1)
    {
        printf("Queue 1 is empty\n");
        return ;
    }
    printf("Contents of queue 1\n");
    for(i=f1;i<=r1;i++)
    {
        printf("%d\n",q1[i]);
    }
}
void displayQ2()
{
    int i;
    if(f2>r2)
    {
        printf("Queue 2 is empty\n");
        return ;
    }
    printf("Contents of queue 2\n");
    for(i=f2;i<=r2;i++)
    {
        printf("%c\n",q2[i]);
    }
}
void cal()
{
    while(f1<=r1 || f2<=r2)
    {
        if(f1<=r1)
        q[++r]=q1[f1++]+'0';
        if(f2<=r2)
        q[++r]=q2[f2++];
    }
    printf("Output:\n");
    for(int i=f;i<=r;i++)
        printf("%c ",q[i]);
}
void main()
{
    int choice;
    for(;;)
    {
        printf("\n1:Insert integer rear\n2:Insert character rear\n3:Delete integer front\n4:Delete character front\n5:Display integer queue\n6:Display character queue\n7:Output\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the integer item to be inserted\n");
            scanf("%d",&item1);
            insertrear1();
            break;
            case 2:printf("Enter the character item to be inserted\n");
            scanf(" %c",&item2);
            insertrear2();
            break;
            case 3:item1=deletefront1();
            if(item1==-1)
                printf("Queue 1 is empty\n");
            else
                printf("Item deleted in queue 1=%d\n",item1);
            break;
            case 4:item1=deletefront2();
            if(item2=='*')
                printf("Queue 2 is empty\n");
            else
                printf("Item deleted in queue 2=%c\n",item2);
            break;
            case 5:displayQ1();
            break;
            case 6:displayQ2();
            break;
            case 7:cal();
            exit(0);
            default:printf("Invalid choice\n");
        }
    }
}
