struct node
{
    int data;
    struct node*link;
};
#include<stdio.h>
#include<stdlib.h>
void enqueue(int);
void dequeue();
void display();
void push(int);
void pop();


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
        while(t->link!=NULL)
        {
            printf("%d ",t->data);
            t=t->link;
        }
        printf("%d\n",t->data);
    }
}
void dequeue()
{
    
    if(f==NULL && r==NULL)
    {
        printf("Queue underflow");
    }
    struct node*t=f;
    int item=f->data;
    push(item);
    f=f->link;
    free(t);
}
struct nodes
{
    int data;
    struct nodes* link;
};
struct nodes*top=NULL;
void push(int x)
{
    struct nodes*n=malloc(sizeof(struct nodes));
    n->data=x;
    n->link=top;
    top=n;
}

void pop()
{   
    struct nodes*temp=top;
    if(top==NULL)
    {
        printf("Underflow");
    }
    else
    {
        int item=top->data;
        enqueue(item);
        top=temp->link;
        free(temp);
    }
}
void reverse()
{
  while(f!=NULL)
  {
      dequeue();
  }
  f=r=NULL;
  while(top!=NULL)
  {
      pop();
  }
  printf("The reversed queue is:");
  display();
}

void main()
{
    int n,c;
    char ch;
    printf("1:Insert\n2:Reverse\n3:Display\n");
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
            case 2:reverse();
                    break;
            case 3:display();
                    break;
            default:printf("Enter a valid choice");
        }
        printf("Do you want to repeat(y/n)?");
        scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');
}
