struct node
{
    int number;
    char name[20];
    int tmark;
    struct node*link;
};
struct node*h;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void display();
void insert_f(int n,char na[],int tm)
{
    struct node*t=malloc(sizeof(struct node));
    t->number=n;
    strcpy(t->name,na);
    t->tmark=tm;
    t->link=h;
    h=t;
}
void delete(int nu)
{
    struct node*t=h,*p;
    while(t->number!=nu)
    {
        p=t;
        t=t->link;
    }
    printf("Deletd:%d",t->number);
    p->link=t->link;
    free(t);
}
void search()
{
    int n;
    printf("Enter the number to be searched for:");
    scanf("%d", &n);
    struct node *p = h;
    while (p != NULL)
    {
        if (p->number == n)
        {
            printf("Found. Number:%d\nName:%s\nMark:%d\n", p->number, p->name, p->tmark);
            return;  
        }
        p = p->link;
    }
    printf("Not found\n");
}

void sort()
{
    struct node*pt1,*pt2;
    int n,t,mtem;char tem[50];
    printf("Enter the number of nodes");
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        pt1=h;
        pt2=pt1->link;
        for(int j=0;j<n-i-1;j++)
        {
            if(pt1->number>pt2->number)
            {
                t=pt1->number;
                pt1->number=pt2->number;
                pt2->number=t;
                strcpy(tem,pt1->name);
                strcpy(pt1->name,pt2->name);
                strcpy(pt2->name,tem);
                mtem=pt1->tmark;
                pt1->tmark=pt2->tmark;
                pt2->tmark=mtem;
            }
            pt1=pt2;
            pt2=pt2->link;
        }
    }
    printf("Sorting complete");
    display();
}
void display()
{
    struct node* t;
    if(h==NULL)
    {
        printf("Empty");
    }
    else
    {
        t=h;
        while(t!=NULL)
        {
            printf("Number:%d\tName:%s\tMark:%d\n",t->number,t->name,t->tmark);
            t=t->link;
        }
    }
}
void main()
{
    int choice=1;
    int num,m,key;
    char nam[50];
    printf("1-Inseert at begining\n2-Delete based on number\n3-Search based on number\n4-Sort based on number\n5-Display\n");
    do
    {
        printf("Enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the number,name and total mark");
                   scanf("%d %s %d",&num,nam,&m);
                   insert_f(num,nam,m);
                   break;
            case 2:printf("Enter the number to be deleted:");
                   scanf("%d",&key);
                   delete(key);
                   break;
            case 3:search();
                   break;
            case 4:sort();
                   break;
            case 5:display();
                   break;
            default:printf("Enter a valid choice");
        }
    }while(choice<=5);
}
/*void delete(int nu)
{
    struct node *t = h, *p = NULL;

    // Check if the first node needs to be deleted
    if (t != NULL && t->number == nu)
    {
        h = t->link;
        printf("Deleted: %d\n", t->number);
        free(t);
        return;
    }

    // Search for the node to delete
    while (t != NULL && t->number != nu)
    {
        p = t;
        t = t->link;
    }

    // Check if the node was found
    if (t == NULL)
    {
        printf("Node with number %d not found\n", nu);
        return;
    }

    // Node found, delete it
    p->link = t->link;
    printf("Deleted: %d\n", t->number);
    free(t);
}*/

