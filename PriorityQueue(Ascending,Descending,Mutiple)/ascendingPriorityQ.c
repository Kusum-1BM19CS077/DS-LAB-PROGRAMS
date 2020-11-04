#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 3

int pq[MAX];
int count = 0;
int d = 0;

void insert(int data){
   int i = 0;
      if(count==MAX)
      {
          printf("Queue overflow\n");
          return;
      }
      if(count == 0){
         pq[count++] = data;
      }else{
			for(i = count - 1; i >= 0; i-- ){
            if(data<pq[i]){
               pq[i+1] = pq[i];
            }else{
               break;
            }
         }


         pq[i+1] = data;
         count++;
      }

}

int removeData(){

   return pq[d++];
}
void display()
{int i;
if (count==0)
{
	printf("queue is empty\n");
	return;
}
printf("Contents of queue: ");
for(i=d;i<count;i++)
{
	printf("%d ",pq[i]);
}
printf("\n");
}

int main() {
    int choice,item;
	for(;;)
	{
		printf("\n1:insert\n2:delete_smallest\n3:display\n4:exit\n");
		printf("Enter the choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the item to be inserted :");
			scanf("%d",&item);
			insert(item);
			break;
			case 2:item=removeData();
			if(item==-1)
			printf("Queue is empty\n");
			else
			printf("item deleted=%d\n",item);
			break;
			case 3:display();
			break;
			default:exit (0);

		}

	}

   }
