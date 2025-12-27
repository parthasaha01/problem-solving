#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    long int N, i, ans1, ans2, k, l;

    while(scanf("%ld", &N)==1)
    {
        long int ara[N];

        k=0;
        l=0;

        for(i=0; i<N; i++)
        {
            scanf("%ld", &ara[i]);

            if(ara[i] % 2 == 0)
            {
                k++;
                ans1 = i;
            }
            else
            {
                l++;
                ans2 = i;
            }
        }

        if(k < l)
            printf("%ld\n", ans1+1);
        else
            printf("%ld\n", ans2+1);
    }

        return 0;
}
