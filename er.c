#include<stdio.h>
#include<string.h>
#define invalid -9999
#define size 20
int a[20],k=0;
void infixtopost(char*,char*);
void main()
{
        char E[50],pf[50];
        printf("Enter the infix expression:\n");
        scanf(" %s",E);
        infixtopost(E,pf);
        printf("Postfix expression is %s\n",pf);
}
int icp(char ch)
{
        if(ch=='+'||ch=='-')
                return 1;
        else if(ch=='*'||ch=='/')
                return 3;
        else if(ch=='^')
                return 6;
        else if(ch=='(')
                return 7;
        else if(ch==')')
                return 0;
}
int isp(char ch)
{
        if(ch=='+'||ch=='-')
                return 2;
        else if(ch=='*'||ch=='/')
                return 4;
        else if(ch=='^')
                return 5;
        else if(ch=='(')
                return 0;
}
void infixtopost(char e[],char p[])
{
        a[k]='(';
        strcat(e,")");
        int i=0,j=0;
        char optr,item;
        while(e[i]!='\0')
        {
                item=e[i];
                optr=a[k];
                if(item>='0' && item<='9')
                {
                        p[j]=e[i];
                        j++;
                }
                else if(item==')')
                {
                        while(optr!='(')
                        {
                                p[j]=a[k];
                                j++;
                                optr=a[k];
                        }
                        k--;
                }
                else
                {
                        while(isp(optr)>=icp(item))
                        {
                                p[j]=a[k];
                                j++;k--;
                                optr=a[k];
                        }
                        k++;
                        a[k]=item;
                }
                i++;
                p[j]='\0';
        }
}

