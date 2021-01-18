/*The XYZ clinic has a waiting room with ten chairs. The chairs available in the clinic should
be designed to occupy based on the FIFO architecture and also more efficiently by allowing
customers to occupy the seats vacantly. In the case of no vacant seats in the waiting room, a
“Waiting Room Full” message should be displayed at the reception counter. Develop an
application(C Program) for the above scenario with a suitable data structure.*/
#include<stdio.h>
#include<stdlib.h>
#define QUE_SIZE 3
int item,front=0,rear=-1,q[QUE_SIZE],count=0;
void insertrear()
{
if(count==QUE_SIZE)
{
printf("Waiting Room Full\n");
return;
}
rear=(rear+1)%QUE_SIZE;
q[rear]=item;
count++;
}
int deletefront()
{
if(count==0) return -1;
item=q[front];
front=(front+1)%QUE_SIZE;
count=count-1;
return item;
}
void displayQ()
{
int i,f;
if(count==0)
{
printf("Vacant waiting room\n");
return;
}
f=front;
printf("Waiting room token numbers \n");
for(i=1;i<=count;i++)
{
printf("%d\n",q[f]);
f=(f+1)%QUE_SIZE;
}
}
void main()
{
 int choice;

 for(;;)
 {
 printf("\n1:Enter waiting room\n2:Enter clinic\n3:Display token number\n4:Exit\n");
 printf("Enter the choice\n");
 scanf("%d",&choice);

 switch(choice)
 {
 case 1:printf("Enter your token number\n");
	scanf("%d",&item);
	insertrear();
	break;
 case 2:item=deletefront();
	if(item==-1)
	printf("Waiting Room Full\n");
	else
	printf("Token number %d exited waiting room\n",item);
	break;
 case 3:displayQ();
	break;
 case 4:exit(0);
 break;
 default:printf("Invalid choice\n");
}
}
}

