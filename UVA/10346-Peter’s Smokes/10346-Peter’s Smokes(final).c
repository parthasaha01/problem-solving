#include<stdio.h>
int main()
{
    int n,k,sum;

    while(scanf("%d %d", &n, &k) == 2 && k > 1)
    {
        sum = n;
        while(n >= k)
        {
            sum = sum + n/k;
            n = (n/k)+(n%k);
        }
        printf("%d\n",sum);
    }

    return 0;
}
