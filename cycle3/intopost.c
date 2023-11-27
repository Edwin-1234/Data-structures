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
int eval(char p[])
{
    int i,op1,op2,val;
    char sy;
    i=0;
    while(p[i]!=0)
    {
        sy=p[i];
        if(sy>='0'&&sy<='9')
        {
            int num=sy-'0';
            push(num);
        }
        else if((sy=='+')||(sy=='-')||(sy=='*')||(sy=='/'))
        {
            op1=pop();
            op2=pop();
            switch(sy)
            {
                case '+':val=op2+op1;
                            break;
                case '-':val=op2-op1;
                            break;
                case '*':val=op2*op1;
                            break;
                case '/':val=op2/op1;
                            break;
            }
            push(val);
        }
        i++;
    }
    val=pop();
    return val;
}
int main()
{
    char e[20],p[30];
    
    printf("Enter infix expression:");
    scanf(" %[^\n]",e);
    intopost(e,p);
    printf("The postfix expression is:%s\n",p);
    int v=eval(p);
    printf("value=%d",v);

    return 0;
}
