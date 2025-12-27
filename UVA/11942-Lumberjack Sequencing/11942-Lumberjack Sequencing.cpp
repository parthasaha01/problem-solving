#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int T, i, ara[10], P, Q, diff;

    scanf("%ld", &T);

    printf("Lumberjacks:\n");

    while(T--)
    {
        P=Q=0;

        scanf("%d", &ara[0]);

        for(i=1; i<10; i++)
        {
            scanf("%d", &ara[i]);

            diff = ara[i]-ara[i-1];

            if(diff > 0)
                ++P;
            else
                ++Q;
        }

        if(!P || !Q)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }

    return 0;
}
