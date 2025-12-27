#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int T, i, n, k, test=1, res, diff;
    char b[550];
    int c[100];

    scanf("%d", &T);

    while(T--)
    {
        int a[100]={0};
        res=0;

        scanf("%d %d %s", &n, &k, b);

        for(i=0; i<n; i++)
        {
            if(a[b[i]])
            {
                diff = i-c[b[i]];

                if(diff <= k)
                {
                    ++res;
                }
                c[b[i]] = i;
            }
            else
            {
                a[b[i]]=1;
                c[b[i]] = i;
            }
        }

        printf("Case %d: %d\n", test++, res);
    }

    return 0;
}
