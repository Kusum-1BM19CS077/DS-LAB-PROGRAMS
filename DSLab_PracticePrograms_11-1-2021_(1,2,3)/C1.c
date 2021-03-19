#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 3
int t1=-1,t2=-1; int s1[3],s2[3]; int item1,item2,c1=0,c2=0;
void push1() {
if(t1==STACK_SIZE -1)
{ printf("Stack 1 Overflow\n");
return;
}
t1=t1+1;
s1[t1]=item1;
}
void push2() {
if(t2==STACK_SIZE -1)
{ printf("Stack 2 Overflow\n");
return;
}
t2=t2+1;
s2[t2]=item2;
}
int pop1() {
if(t1==-1)
return -1;
return s1[t1--];
}
int pop2() {
if(t2==-1)
return -1;
return s2[t2--];
}
void display1() {
int i;
if(t1==-1) {
printf("Stack 1 is empty\n");
return;
}
printf("Contents of the stack 1:\n");
for(i=0;i<=t1;i++) {
printf("%d\n",s1[i]);
} }
void display2() {
int i;
if(t2==-1) {
printf("Stack 2 is empty\n");
return;
}
printf("Contents of the stack 2:\n");
for(i=0;i<=t2;i++) {
printf("%d\n",s2[i]);
} }
void cal()
{
    if(t1==t2)
    {  int x=1;
        for(int k=0;k<t1;k++)
        {
            if(s1[k]!=s2[k])
            {
                x=0;
                break;
            }
        }
        if(x==1)
            printf("EQUAL");
        else
            printf("NOT EQUAL");
    }
    else
        printf("NOT EQUAL");
}
void main() {
int item_deleted;
int choice;
for(;;) {
printf("\n1.Push Stack1\n2.Push Stack2\n3.Pop Stack1\n4.Pop Stack2\n5.Display Stack1\n6.Display Stack2\n7.Output\n");
printf("Enter the choice\n");
scanf("%d",&choice);
switch(choice) {
case 1:printf("Enter the item to be inserted in stack 1\n");
scanf("%d",&item1);
push1();
break;
case 2:printf("Enter the item to be inserted in stack 2\n");
scanf("%d",&item2);
push2();
break;
case 3:item_deleted=pop1();
if(item_deleted==-1)
printf("Stack 1 is empty\n");
else
printf("Item deleted in Stack 1 is %d\n",item_deleted);
break;
case 4:item_deleted=pop2();
if(item_deleted==-1)
printf("Stack 2 is empty\n");
else
printf("Item deleted in Stack 2 is %d\n",item_deleted);
break;
case 5:display1();
break;
case 6:display2();
break;
case 7:printf("Output\n");
cal();
exit(0);
default:printf("Invalid choice\n");
 } } }
