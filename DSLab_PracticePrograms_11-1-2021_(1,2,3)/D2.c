#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 10
int top=-1,t=-1,i=0,count=0; int s1[10],s2[10]; int item;

void push() {
if(count==STACK_SIZE)
{ printf("Queue Overflow\n");
return;
}
top=top+1;
s2[top]=item;
count++;
}
int pop() {
    t=-1;
    if(count==0)
return -1;
    int z=top;
    while(z!=i-1)
        s1[++t]=s2[z--];
    count--;
    i++;
    return s1[t];

}
void display() {
if(count==0) {
printf("Queue is empty\n");
return;
}
printf("Contents of the queue:\n");
for(int j=i;j<=top;j++) {
printf("%d\n",s2[j]);
} }
void main() {
int item_deleted;
int choice;
for(;;) {
printf("\n1.Insertrear\n2.Delete front\n3.Display\n4.Exit\n");
printf("Enter the choice\n");
scanf("%d",&choice);
switch(choice) {
case 1:printf("Enter the item to be inserted\n");
scanf("%d",&item);
push();
break;
case 2:
item_deleted=pop();
if(item_deleted==-1)
printf("Queue is empty\n");
else
printf("Item deleted is %d\n",item_deleted);
break;
case 3:display();
break;
default:exit(0);
 } } }
