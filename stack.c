#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
int stack[100],top=-1,n;
void push()
{
    int element;
    if(top==n-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
     printf("Enter element:");
     scanf("%d",&element);
     stack[++top]=element;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("Empty Stack.Can't delete!\n");
    }
    else
    {
        top--;
    }
}
void display()
{
    int i;
    if(top>=0)
    {
        printf("Stack elements are:\n");
        for(i=top;i>=0;i--)
            printf("%d\n",stack[i]);
    }
    else
        printf("Empty Stack\n");
}
int main()
{
    int choice;
    printf("Enter the maximum size of the stack\n");
    scanf("%d",&n);

    while(1){
            printf("\n\nEnter your operation\n1.push\n2.pop\n3.display\n4.exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:push();
        break;
        case 2:pop();
        break;
        case 3:display();
        break;
        case 4:exit(-1);
        break;
        default:printf("Enter right choice of operation\n");
    }
    }
    return 0;
}
