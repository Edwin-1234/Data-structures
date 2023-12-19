#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff,exp,expy;
    struct node*link;
};
struct node* ph,*qh,*rhead;
struct node* rdpoly()
{
    int n;
    struct node*ptr;struct node*head=NULL;
    printf("Enter the no. of terms of the polynomial:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        struct node*ne=malloc(sizeof(struct node));
        printf("Enter the coeff%d and exp%d expy%d:",i,i,i);
        scanf("%d %d %d",&ne->coeff,&ne->exp,&ne->expy);
        ne->link=NULL;
        if(head==NULL)
        {
            head=ne;
            ptr=head;
        }
        else
        {
            ptr->link=ne;
            ptr=ne;
        }
    }
     return head;
}
void display(struct node*head)
{
    struct node* t=head;
    if(t==NULL)
    {
        printf("Empty");
    }
    else
    {
        while(t->link!=NULL)
        {
            printf("%dx^%dy^%d+",t->coeff,t->exp,t->expy);
            t=t->link;
        }
        printf("%dx^%dy^%d",t->coeff,t->exp,t->expy);
    }
}
struct node*add()
{
    struct node*rh=NULL;struct node*n;
    struct node*p;
    struct node*q;
    struct node*r;
    p=ph;
    q=qh;
    while(p!=NULL && q!=NULL)
    {
        if((p->exp==q->exp)&&(p->expy==q->expy))
        {
            n=malloc(sizeof(struct node));
            n->coeff=p->coeff+q->coeff;
            n->exp=p->exp;
            n->expy=p->expy;
            n->link=NULL;
            p=p->link;q=q->link;
        }
        else if((p->exp> q->exp) || ((p->exp==q->exp)&&( p->expy>q->expy)))
      
        {
            n=malloc(sizeof(struct node));
            n->coeff=p->coeff;
            n->exp=p->exp;
            n->expy=p->expy;
            n->link=NULL;
            p=p->link;
        }
        else
        {
            n=malloc(sizeof(struct node));
            n->coeff=q->coeff;
            n->exp=q->exp;
            n->expy=q->expy;
            n->link=NULL;
            q=q->link;
        }
        if(rh==NULL)
        {
            rh=n;
            r=n;
        }
        else
        {
            r->link=n;
            r=n;
        }
    }
    while(p!=NULL)
    {
        n=malloc(sizeof(struct node));
        n->coeff=p->coeff;n->exp=p->exp;
        n->expy=p->expy;
        p=p->link;
        if(rh==NULL)
        {
            rh=n;
            r=n;
        }
        else
        {
            r->link=n;
            r=n;
        }
    }
    while(q!=NULL)
    {
        n=malloc(sizeof(struct node));
        n->coeff=q->coeff;n->exp=q->exp;
        n->expy=q->expy;
        q=q->link;
        if(rh==NULL)
        {
            rh=n;
            r=n;
        }
        else
        {
            r->link=n;
            r=n;
        }
    }
    return rh;
}
void main()
{
    printf("Enter the details of first polynomial\n");
    ph=rdpoly();
    printf("Enter the details of first polynomial\n");
    qh=rdpoly();
    printf("First polynomial:");
    display(ph);
    printf("\n");
    printf("First polynomial:");
    display(qh);
    printf("\n");
    rhead=add();
    printf("Sum:");
    display(rhead);
}
    
    
