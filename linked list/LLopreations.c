struct node
{
    int data;
    struct node*link;
};
struct node*h;
#include<stdio.h>
#include<stdlib.h>
void insert_f(int x)
{
    struct node*t=malloc(sizeof(struct node));
    t->data=x;
    t->link=h;
    h=t;
}
void insert_r(int x)
{
    struct node*pt=h;
    struct node*t=malloc(sizeof(struct node));
    while(pt->link!=NULL)
    {
        pt=pt->link;
    }
    pt->link=t;
    t->data=x;
    t->link=NULL;
}
void insert_p(int x,int key)
{
    struct node*temp=h,*new;
    while(temp->data!=key)
    {
        temp=temp->link;
    }
    new=malloc(sizeof(struct node));
    new->link=temp->link;
    new->data=x;
    temp->link=new;
}
void delete_f()
{
    struct node*t=h;
    h=h->link;
    free(t);
}
void delete_r()
{
    struct node*temp=h,*prev;
    while(temp->link!=NULL)
    {
        prev=temp;
        temp=temp->link;
    }
    prev->link=NULL;
    free(temp);
}
void delete_p(int key)
{
    struct node*temp=h,*prev;
    while(temp->data!=key)
    {
        prev=temp;
        temp=temp->link;
    }
    prev->link=temp->link;
    free(temp);
}
void display()
{
    struct node* t=h;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->link;
    }
    printf("\n");
}
void main()
{
    int key,item,c;
    char ch;
    printf("1:Insert front\n2:Insert rear\n3:Insert after a number\n4:Delete front\n5:Delete rear\n6:Delete a number\n7:Display\n");
    do
    {
        printf("Enter a choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("Enter the number to be inserted:");
                    scanf("%d",&item);
                    insert_f(item);
                    break;
            case 2:printf("Enter the number to be inserted:");
                    scanf("%d",&item);
                    insert_r(item);
                    break;
            case 3:printf("Enter the number to be inserted:");
                    scanf("%d",&item);
                    printf("Enter the key:");
                    scanf("%d",&key);
                    insert_p(item,key);
                    break;
            case 4:delete_f();
                    break;
            case 5:delete_r();
                    break;  
            case 6:printf("Enter the number to be deleted:");
                    scanf("%d",&item);
                    delete_p(item);
                    break;
            case 7:display();
                    break;
            default:printf("Enter a valid choice\n");
        }
        printf("Do you want to repeat(y/n)?");
        scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');
}
