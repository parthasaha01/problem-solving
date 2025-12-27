#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    long int N, i, p, result, diff;

    while(scanf("%ld", &N)==1)
    {
        long int ara[N];
        long int res[3005]={0};
        p=0;
        result = 1;

        for(i=0; i<N; i++)
        {
            scanf("%ld", &ara[i]);

            if(p)
            {
                diff=abs(ara[i]-ara[i-1]);
                res[diff]=1;
            }
            p=1;
        }

        for(i=1; i<N; i++)
        {
            if(!res[i])
            {
                result = 0;
                goto line;
            }
        }

        line:

        if(result)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }

    return 0;
}
