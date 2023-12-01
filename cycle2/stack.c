#include<stdio.h>
#define invalid -9999
#define size 5
int s[20],top=-1;
void push(int item)
{
        if(top==(size-1))
                printf("Stack overflow\n");
        else
        {
                top=top+1;
                s[top]=item;
        }
}

int pop()
{       int item;
        if(top==-1)
        {
                printf("Stack undreflow\n");
                return invalid;
        }
        else
        {
                item=s[top];
                top--;
                return item;
        }
}

void display()
{       int i;
        if(top==-1)
                printf("Stack is empty\n");
        else
                for(i=0;i<=top;i++)
                        printf("%d ",s[i]);
}

void main()
{       int n,num,item;
        char ch;
        do
        {
                printf("1:Push\n2:Pop\n3:Display\n");
                printf("Enter a number:");
                scanf("%d",&n);
                switch(n)
                {
                        case 1:printf("Enter the number to be inserted\n");
                                scanf("%d",&num);
                                push(num);
                                break;
                        case 2:item=pop();
                                printf("the deleted element is %d\n",item);
                                break;
                        case 3:display();
                                break;
                        default:printf("Enter a valid number\n");
                }
                printf("Do you want to repeat(y/n)?");
                scanf(" %c",&ch);
        }while(ch=='Y' || ch=='y');
}
