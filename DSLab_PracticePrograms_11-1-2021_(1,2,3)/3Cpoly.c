#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
 int cf;
 int px;
 int py;
 int flag;
 struct node *link;
};
typedef struct node *node;

node getnode()
{
 node x;
 x=(node)malloc(sizeof(struct node));
 if(x == NULL)
 {
   printf("out of memory\n");
   exit(0);
 }
 return x;
}

node insert_rear(int cf,int x,int y,node head)
{
 node temp,cur;
 //int flag;
 temp=getnode();
 temp->cf=cf;
 temp->px=x;
 temp->py=y;
 temp->flag=0;
 cur=head->link;
 while(cur->link!=head)
 cur=cur->link;
 cur->link=temp;
 temp->link=head;
 return head;
}

node read_poly(node head)
{
 int i,n;
 int cf,px,py;
 printf("Enter number of terms: ");
 scanf("%d",&n);
 for (i=1;i<=n;i++)
 {
   printf("enter the %d term\n",i);
   printf("Coefficient:");
   scanf("%d",&cf);
   printf("Power of x:");
   scanf("%d",&px);
   printf("Power of y:");
   scanf("%d",&py);
   head=insert_rear(cf,px,py,head);
 }
 return head;
}

void display(node head)
{
 node temp;
 if(head->link==head)
 {
   printf("Polynomial does not exist\n");
   return;
 }
 temp=head->link;
 while(temp->link!=head)
 {
   printf("%dx^%dy^%d + ",temp->cf,temp->px,temp->py);
   temp=temp->link;
 }
   printf("%dx^%dy^%d",temp->cf,temp->px,temp->py);
 printf("\n");
}

node add_poly(node h1,node h2,node h3)
{
 node p1,p2;
 int x1,x2,y1,y2,cf1,cf2,cf;
 p1=h1->link;
 while(p1!=h1)
 {
   x1=p1->px;
   y1=p1->py;
   cf1=p1->cf;

   p2=h2->link;
   while(p2!=h2)
   {
     x2=p2->px;
     y2=p2->py;
     cf2=p2->cf;
     if(x1==x2 && y1==y2)
     break;
     p2=p2->link;
   }
   if(p2!=h2)
   {
     cf=cf1+cf2;
     p2->flag=1;
     if(cf!=0)
     h3=insert_rear(cf,x1,y1,h3);
   }
   else
   h3=insert_rear(cf1,x1,y1,h3);
   p1=p1->link;
 }
 p2=h2->link;
 while(p2!=h2)
 {
   if(p2->flag==0)
   {
     h3=insert_rear(p2->cf,p2->px,p2->py,h3);
   }
   p2=p2->link;
 }
 return h3;
}

void evaluate(node head,int x,int y)
{
    int sum=0;
    node poly = head->link;
    while(poly != head )
    {
        sum= sum + (poly->cf*pow(x,poly->px)*pow(y,poly->py));
        poly=poly->link;
    }
    printf("Value of polynomial after substitution:%d",sum);
}

int main()
{
 node h1,h2,h3;
 h1=getnode();
 h2=getnode();
 h3=getnode();
 h1->link=h1;
 h2->link=h2;
 h3->link=h3;
 printf("Enter the first polynomial:\n");
 h1=read_poly(h1);
 printf("Enter the second polynomial:\n");
 h2=read_poly(h2);
 h3=add_poly(h1,h2,h3);
 printf("The first polynomial: ");
 display(h1);
 printf("The second polynomial: ");
 display(h2);
 printf("The sum of two polynomials: ");
 display(h3);
 int x,y;
 printf("Enter value of x:");
 scanf("%d",&x);
 printf("Enter value of y:");
 scanf("%d",&y);
 evaluate(h3,x,y);
}
