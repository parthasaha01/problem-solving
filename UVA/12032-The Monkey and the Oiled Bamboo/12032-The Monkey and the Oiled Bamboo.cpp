#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    long int N, T, i, Max, diff, test=1, flag, k, M, m;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%ld", &N);

        long int a[N], b[N];
        scanf("%ld", &a[0]);

        Max=a[0];
        m=0;
        k=m;

        b[m++]=Max;

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
        flag=0;
        for(i=k+1; i<m; i++)
        {
            //printf("%ld  ",b[i]);
            if(b[i] == Max)
            {
                flag=1;
                break;
            }
            else if(b[i] == M)
            {
                M--;
            }
            else if(b[i] > M)
            {
                flag=1;
                break;
            }
        }

        //printf("\n%ld\n", Max);

        if(flag)
            printf("Case %ld: %ld\n", test++, Max+1);
        else
            printf("Case %ld: %ld\n", test++, Max);

    }

    return 0;
}
