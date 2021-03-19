#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 10
int top=-1; int s[10]; int item; int o[10],t=-1;
void push() {
if(top==STACK_SIZE -1)
{ printf("Stack Overflow\n");
return;
}
top=top+1;
s[top]=item;
}
int pop() {
if(top==-1)
return -1;
return s[top--];
}
void display() {
int i;
if(top==-1) {
printf("Stack is empty\n");
return;
}
printf("Contents of the stack:\n");
for(i=0;i<=top;i++) {
printf("%d\n",s[i]);
} }
void duplicate() {
    o[++t]=s[top--];
    while(top!=-1)
    {
    if(s[top]==o[t])
    --top;
    else
        o[++t]=s[top--];
    }
    for(int i=t;i>=0;i--)
    {
        printf("%d ",o[i]);
    }

}
void main() {
int item_deleted;
int choice;
for(;;) {
printf("\n1.Push\n2.Pop\n3.Display\n4.End\n");
printf("Enter the choice\n");
scanf("%d",&choice);
switch(choice) {
case 1:printf("Enter the item to be inserted(ascending only)\n");
scanf("%d",&item);
push();
break;
case 2:item_deleted=pop();
if(item_deleted==-1)
printf("Stack is empty\n");
else
printf("Item deleted is %d\n",item_deleted);
break;
case 3:display();
break;
case 4:
    printf("Values without duplication\n");
    duplicate();
    break;
default: exit(0);
 } } }
