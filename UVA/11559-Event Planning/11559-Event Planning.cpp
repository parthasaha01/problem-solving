#include<iostream>
#include<cstdio>
#include<algorithm>
int main()
{
    long int N, B, H, W, P, a[20], Min, i, k, m, flag, cost;

    while(scanf("%ld %ld %ld %ld", &N, &B, &H, &W) == 4)
    {
        Min = B+1;

        for(k=0; k<H; k++)
        {
            scanf("%ld", &P);
            m=N;
            flag=0;

            for(i=0; i<W; i++)
            {
                scanf("%ld", &a[i]);
            }

            for(i=0; i<W; i++)
            {
                if(a[i] >= N)
                {
                    flag=1;
                    //if(a[i] < m)
                        //m=a[i];
                    break;
                }
            }

            if(flag)
            {
                cost = N*P;
                if(cost < Min)
                    Min=cost;
            }
        }

        if(Min <= B)
            printf("%ld\n", Min);
        else
            printf("stay home\n");
    }

    return 0;
}
