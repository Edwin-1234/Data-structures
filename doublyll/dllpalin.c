struct node
{
    int data;
    struct node* ll;
    struct node* rl;
};
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node*head=NULL;
void insert(char ch)
{
    struct node*n=malloc(sizeof(struct node));
    n->data=ch;
    n->rl=NULL;
    if(head==NULL)
    {
        head=n;
        n->ll=NULL;
    }
    else
    {
        struct node*ptr=head;
        while(ptr->rl!=NULL)
        {
            ptr=ptr->rl;
        }
        ptr->rl=n;
        n->ll=ptr;
    }
}
int ispalindrome()
{
    struct node* ptr1,*ptr2;
    ptr1=head;
    ptr2=head;
    while(ptr2->rl!=NULL)
    {
        ptr2=ptr2->rl;
    }
    while(ptr1!=ptr2 )
    {
        if(ptr1->data!=ptr2->data)
        {
            return 0;
        }
        ptr1=ptr1->rl;
        ptr2=ptr2->ll;
    }
    return 1;
}
void main()
{
    char arra[30];
    printf("Enter the string:");
    scanf(" %[^\n]",arra);
    for(int i=0;i<strlen(arra);i++)
    {
        insert(arra[i]);
    }
    if(ispalindrome())
    {
        printf("%s Is a palindrome",arra);
    }
    else
    {
        printf("%s Not a palindrome",arra);
    }

}
