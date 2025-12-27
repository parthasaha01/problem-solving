#include<cstdio>
#include<algorithm>
using namespace std;
long int totalvalue(void);
int main()
{
    long int value, T;

    scanf("%ld", &T);

    while(T--)
    {
        value=totalvalue();

        if(value == -1)
            printf("Too expensive\n");
        else
            printf("%ld\n", value);
    }

    return 0;
}
long int totalvalue(void)
{
    long int ara[40], i=0, N, j, Min=0, power, k;

    while(1)
    {
        scanf("%ld", &ara[i]);
        if(ara[i] == 0)
            break;

        i++;
    }

    N = i;
    j=1;
    sort(ara, ara+N);

    for(i=N-1; i>=0; i--)
    {
        power=ara[i];

        for(k=j; k>1; k--)
            power *= ara[i];

        Min += (2*power);

        if(Min > 5000000)
            return -1;
        j++;
    }

    return Min;
}
