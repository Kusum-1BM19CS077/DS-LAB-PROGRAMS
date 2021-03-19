#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *previous;
    struct node *next;
};

int size = 0;
struct node *head, *tail = NULL;

void addNode() {
   int data;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &data);
    newNode->data = data;


    if(head == NULL) {

        head = tail = newNode;

        head->previous = NULL;

        tail->next = NULL;
    }
    else {

        tail->next = newNode;

        newNode->previous = tail;

        tail = newNode;

        tail->next = NULL;
    }

    size++;
}


void rotateList() {
     int n;
    struct node *current = head;
      printf("Enter number of nodes to be rotated: ");
      scanf("%d", &n);

    if(n == 0 || n >= size)
    {printf("Invalid number(List remains unchanged)\n");
     return;
    }

    else {

        for(int i = 1; i < n; i++)
            current = current->next;


        tail->next = head;

        head = current->next;

        head->previous = NULL;

        tail = current;

        tail->next = NULL;
    }
}


void display() {

    struct node *current = head;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    while(current != NULL) {

        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int ch;
    printf("1.Insert \n2.Display \n3.Rotate \n4.Exit \n");
    do{
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {

       case 1:  addNode(); break;

       case 2: printf("Original List: \n");
                display();  break;


       case 3: rotateList();
               printf("Updated List(After rotation): \n");
               display();  break;
       case 4: exit(0);
       default:printf("Invalid input\n");
    }
}while(ch!=0);
    return 0;
}
