#include <stdio.h>
#include<string.h>
int main()
{
    int alph[26],unique,sublen=0,n,start,end,j,i;
    char str[30];
    printf("Enter a string :");
    scanf("%s",str);
    n=strlen(str);
    for(i=0;i<n;i++)
    {   unique=0;
        for(j=0;j<26;j++)
            alph[j]=0;
            
        for(j=i;j<n;j++)
        {
            if(alph[str[j]-'a']==1)
                break;
            else
            {
                alph[str[j]-'a']=1;
                unique++;
            }    
        }
        if(unique>sublen)
        {
            sublen=unique;start=i;end=j;
        }
    }
    printf("lenght of longest substring=%d\n",sublen);
    printf("substring is :");
    for(i=start;i<end;i++)
        printf("%c",str[i]);
    return 0;
}