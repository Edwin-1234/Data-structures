struct node
{
    int data;
    struct node*link;
};
#include<stdio.h>
#include<stdlib.h>
struct node* f=NULL;
struct node*r=NULL;
void enqueue(int x)
{
    struct node*n=malloc(sizeof(struct node));
    n->data=x;
    n->link=0;
    if(f==NULL && r==NULL)
    {
        f=r=n;
    }
    else
    {
        r->link=n;
        r=n;
    }
}
void display()
{
    if(f==NULL && r==NULL)
    {
        printf("Queue underflow");
    }
    else
    {
        struct node*t=f;
        while(t!=NULL)
        {
            printf("%d ",t->data);
            t=t->link;
        }
        printf("\n");
    }
}
void dequeue()
{
    if(f==NULL && r==NULL)
    {
        printf("Queue underflow");
    }
    struct node*t=f;
    printf("Dlelted element is:%d\n",f->data);
    f=f->link;
    free(t);
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
                    enqueue(n);
                    break;
            case 2:dequeue();
                    break;
            case 3:display();
                    break;
            default:printf("Enter a valid choice");
        }
        printf("Do you want to repeat(y/n)?");
        scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');
}
