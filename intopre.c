#include<string.h>
#include <stdio.h>
#define size 20
int s[30],top=-1;
int item;
void push(int item)
{
    if(top==size-1)
    {
        printf("Stack overflow");
    
    }
    else
    {
        top=top+1;
        s[top]=item;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("Stack underflow");
        return -9999;
    }
    else
    {
        item=s[top];
        top=top-1;
        return item;
    }
}
int icp(int c)
{
    if(c=='+'||c=='-')
        return 1;
    if(c=='*'||c=='/')
        return 3;
    if(c=='^')
        return 6;
    if(c=='(')
        return 7;
    if(c==')')
        return 0;
}
int isp(int c)
{
    if(c=='+'||c=='-')
        return 2;
    if(c=='*'||c=='/')
        return 4;
    if(c=='^')
        return 5;
    if(c=='(')
        return 0;
    
}
void intopost(char e[],char post[])
{
    int i=0,j=0;
    char symb,optr;
    push('(');
    strcat(e,")");
    while(e[i]!='\0')
    {
        symb=e[i];
        optr=s[top];
        if(symb>='0'&&symb<='9')
        {
            post[j]=e[i];
            j++;
        }
         else if(symb==')')
        {
            while(optr!='(')
            {
                post[j]=pop();
                j++;
                optr=s[top];
            }
            pop();
        }
        else 
        {
            while(isp(optr)>=icp(symb))
            {
                post[j]=pop();
                j++;
                optr=s[top];
            }
            push(symb);
        }
        i++;
    }
}
void reverse1(char e[],char re[])
{
    int l=0,r=0;
    for(r=0;e[r]!='\0';r++);
    r--;
    while(l<r)
    {
        char tem=e[l];
        e[l]=e[r];
        e[r]=tem;
        l++;r--;
    }
    for(int i=0;i<strlen(e);i++)
    {
        re[i]=e[i];
    }
}
int main()
{
    char e[20],p[30],r[30],r1[30];
    
    printf("Enter infix expression:");
    scanf(" %[^\n]",e);
    reverse1(e,r);
    intopost(r,p);
    reverse1(p,r1);
    printf("The prefix expression is:%s\n",r1);
    
    return 0;
}
