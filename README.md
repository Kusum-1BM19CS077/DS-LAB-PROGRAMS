#include <stdio.h>
struct student
{
    char id[20];
    int age;
    int marks;
};

int main()
{
    struct student s;
    int isvalid=0;
    printf("Enter student ID:\n");
    scanf("%s",s.id);
    printf("Enter student age:\n");
    scanf("%d",&s.age);
    printf("Enter student marks:\n");
    scanf("%d",&s.marks);
    if(s.age>20 && s.marks>=0 && s.marks<=100)
    {
        isvalid=1;
    }
    else
    {
        printf("Invalid data\n");
    }
    if(isvalid)
    {
        if(s.marks>=65)
        {
            printf("Qualified for admission\n");
        }
        else
        {
            printf("Not qualified for admission\n");
        }
    }
    return 0;
}
