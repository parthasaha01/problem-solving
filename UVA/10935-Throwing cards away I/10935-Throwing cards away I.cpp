#include<cstdio>
using namespace std;
int main()
{
    int n, i, k, p, m, q, r;

    while(scanf("%d", &n) && n)
    {

        int a[51]={0};
        int b[n];
        k=p=0;

        for(i=1; i<=n; i += 2)
        {
            a[i]=1;
            b[k++] = i;
            p++;
        }

        if(n&1)
            m=0;
        else
            m=1;

        while(p<n)
        {
            i=2;
            while(i<=n)
            {
                if(!a[i])
                {
                    if(m==1)
                    {
                        a[i]=1;
                        b[k++] = i;
                        m=0;
                        p++;
                    }
                    else
                        m=1;
                }
                i++;
            }

        }

        q=k-1;
        r=k-2;

        printf("Discarded cards:");
        for(i=0; i<q; i++)
        {
            if(i<r)
                printf(" %d,", b[i]);
            else
                printf(" %d", b[i]);
        }
        printf("\nRemaining card: %d\n",b[i]);

    }

    return 0;
}
