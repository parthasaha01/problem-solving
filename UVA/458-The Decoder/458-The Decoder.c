#include<stdio.h>
#include<string.h>
int main()
{

    char str1[10000], str2[10000];
    long int i,L1;

    while(gets(str1))
    {
        L1=strlen(str1);

        for(i=0; i < L1 ; i++)
        {
            str2[i]=(str1[i]-7);
        }

        str2[i]='\0';

        puts(str2);
    }

    return 0;
}
