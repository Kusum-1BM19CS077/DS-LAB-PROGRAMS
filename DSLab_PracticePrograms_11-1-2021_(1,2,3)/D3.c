#include<stdio.h>
#include<process.h>
#define QUE_SIZE 5
int item,front=0,rear=-1,q[10],o[10],t=-1;
void insertrear()
{

    if(rear==QUE_SIZE-1)
    {
        printf("Queue overflow\n");
        return ;
    }
    rear=rear+1;
    q[rear]=item;
}
int deletefront()
{

    if(front>rear)
    {
        front=0;
        rear=-1;
        return -1;
    }
    return q[front++];
}
void displayQ()
{
    int i;
    if(front>rear)
    {
        printf("Queue is empty\n");
        return ;
    }
    printf("Contents of queue\n");
    for(i=front;i<=rear;i++)
    {
        printf("%d\n",q[i]);
    }
}
void cal()
{
   int k;
    for(int i=front;i<=rear;i++)
    {
        k=1;
        for(int j=1;j<=10;j++)
        {
          if((q[i]%j)!=0)
          {
              k=0;
            break;
          }
          }
        if(k==1)
        o[++t]=q[i];

    }
    printf("OUTPUT:\n");
    for(int i=0;i<=t;i++)
        printf("%d ",o[i]);
}
void main()
{
    int choice;
    for(;;)
    {
        printf("\n1:Insert rear\n2:Delete front\n3:Display\n4:output\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the item to be inserted\n");
            scanf("%d",&item);
            insertrear();
            break;
            case 2:item=deletefront();
            if(item==-1)
                printf("Queue is empty\n");
            else
                printf("Item deleted=%d\n",item);
            break;
            case 3:displayQ();
            break;
            case 4:cal();
            default:exit(0);
        }
    }
}
