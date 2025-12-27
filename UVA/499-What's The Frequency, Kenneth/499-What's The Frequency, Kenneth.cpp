#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int T, Max, i, L;
    char b[205];

    while(gets(b))
    {
        int a[130]={0};
        Max=0;
        L=strlen(b);

            for(i=0; i<L; i++)
            {
                if(isalpha(b[i]))
                {
                    a[b[i]]++;

                    if(a[b[i]] > Max)
                        Max=a[b[i]];
                }
            }

        for(i=65; i<=90; i++)
        {
            if(a[i] == Max)
            {
                printf("%c", i);
            }
        }
        for(i=97; i<=122; i++)
        {
            if(a[i] == Max)
            {
                printf("%c", i);
            }
        }
        printf(" %d\n", Max);
    }

    return 0;
}
