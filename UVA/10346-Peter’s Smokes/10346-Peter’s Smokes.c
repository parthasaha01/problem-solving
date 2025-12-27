#include<stdio.h>
int main()
{
    int n,k,sum;

    while(scanf("%d %d", &n, &k) == 2 && k > 1)
    {
        sum = 0;
        while(n != 0)
        {
            sum = sum+n;
            n = n/k;
        }
        printf("%d\n",sum);
    }

    return 0;
}
