#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    long int N, T, i, Max, diff, test, k, M, m;

    scanf("%ld", &T);

    for(test=1; test<=T; test++)
    {
        scanf("%ld", &N);

        long int a[N], b[N];

        scanf("%ld", &a[0]);

        m=0;
        b[m++]=a[0];
        Max=a[0];
        k=0;

        for(i=1; i<N; i++)
        {
            scanf("%ld", &a[i]);

            diff = a[i]-a[i-1];

            b[m++] = diff;

            if(diff > Max)
            {
                Max=diff;
                k=m-1;
            }
        }

        M=Max-1;

        for(i=k+1; i<m; i++)
        {
            if(b[i] == M)
            {
                M--;
            }
            else if(b[i] > M)
            {
                Max = Max+1;
                break;
            }
        }

        printf("Case %ld: %ld\n", test, Max);

    }

    return 0;
}
