#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
int main()
{
    int L, i, k, Max, Min, p=0;
    char b[1005];

    while(gets(b))
    {
        if(p)
             printf("\n");

        int a[130]={0};
        L = strlen(b);
        Max=0;
        p=1;
        Min=10005;

        for(i=0; i<L; i++)
        {
            a[b[i]]++;

            if(a[b[i]] > Max)
            {
                Max=a[b[i]];
                continue;
            }

            if(a[b[i]] < Min)
                        Min=a[b[i]];
        }

        for(k=1; k<=Max; k++)
        {
            for(i=127; i>=32; i--)
            {
                if(a[i] == k)
                {
                    printf("%d %d\n", i, k);
                }
            }
        }
    }

    return 0;
}
