#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int L, i, p, k, x, n, m;
    char str[200], rev[200];

    while(scanf("%d", &n) && n)
    {
        getchar();
        gets(str);
        L=strlen(str);
        m=L/n;
        p=m-1;
        k=0;

        while(p<L)
        {
            x=p+m;
            for(i=0; i<m; i++)
            {
                rev[k++]=str[p--];
            }

            p=x;
        }
        rev[k]='\0';

        puts(rev);
    }

    return 0;
}
