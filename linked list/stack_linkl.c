struct node
{
    int data;
    struct node* link;
};
#include<stdlib.h>
#include<stdio.h>
struct node*top=NULL;
void push(int x)
{
    struct node*n=malloc(sizeof(struct node));
    n->data=x;
    n->link=top;
    top=n;
}
void display()
{
    struct node*t=top;
    if(top==NULL)
    {
        printf("Underflow");
    }
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->link;
    }
    printf("\n");
}
void pop()
{   struct node*temp=top;
    if(top==NULL)
    {
        printf("Underflow");
    }
    else
    {
        printf("Poped element is %d\n",temp->data);
        top=temp->link;
        free(temp);
    }
}
void main()
{
    int n,c;
    char ch;
    printf("1:Insert\n2:Delete\n3:Display\n");
    do
    {
        printf("Enter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("Enter the data to be inserted:");
                    scanf("%d",&n);
                    push(n);
                    break;
            case 2:pop();
                    break;
            case 3:display();
                    break;
            default:printf("Enter a valid choice");
        }
        printf("Do you want to repeat(y/n)?");
        scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');
}
