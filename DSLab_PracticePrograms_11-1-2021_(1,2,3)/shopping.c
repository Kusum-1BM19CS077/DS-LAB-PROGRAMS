/*abc shopping mall decided to bill all the items (name, cost) shopped in last-in first-out order. wap to simulate the above scenario using linked list*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
  int info;
  char name[20];
  float cost;
  struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
 {
  printf("Memory full\n");
  exit(0);
 }
 return x;
}
void freenode(NODE x)
{
free(x);
}
NODE insert_front(NODE first,int item,char a[],double c)
{
NODE temp;
temp=getnode();
temp->info=item;
strcpy(temp->name,a);
temp->cost=c;
temp->link=NULL;
if(first==NULL)
return temp;
temp->link=first;
first=temp;
return first;
}
NODE delete_front(NODE first)
{
NODE temp;
if(first==NULL)
{
printf("Stack is empty cannot delete\n");
return first;
}
temp=first;
temp=temp->link;
printf("Item deleted at front-end is=%d %s %f\n",first->info,first->name,first->cost);
free(first);
return temp;
}
void display(NODE first)
{
 NODE temp;
 if(first==NULL)
 printf("Stack empty cannot display items\n");
 printf("Contents of the Stack:\n");
 for(temp=first;temp!=NULL;temp=temp->link)
  {
  printf("%d %s %f\n",temp->info,temp->name,temp->cost);
  }
}
void main()
{
int item,choice,pos;
NODE first=NULL;
char a[20];
float c;
for(;;)
{
printf("\n 1:Add item\n 2:Delete item\n 3:Display bill\n 4:Exit\n");
printf("Enter the choice\n");
scanf("%d",&choice);
switch(choice)
 {
  case 1:printf("Enter the item at front-end\n");
  printf("Enter the serial number:");
	 scanf("%d",&item);
	 printf("Enter the name of the product:");
	 scanf("%s",a);
	 printf("Enter the cost of the product:");
	 scanf("%f",&c);
	 first=insert_front(first,item,a,c);
	 break;
  case 2:first=delete_front(first);
	 break;
  case 3:display(first);
	 break;
 case 4:exit(0);
	 break;
	 default:printf("Invalid choice\n");
 }
}
}

