#include<stdio.h>
#include<math.h>
int main()
{
    long long T, n, res, i, n2, result;

    scanf("%lld", &T);

    while(T--)
    {
        scanf("%lld", &n);

        n2 = sqrt(n);
        res = 0;

        for(i=1; i<=n2; i++)
        {
            res += (n/i);
        }
        result = (res*2)-(n2*n2);

        printf("%lld\n", result);
    }

    return 0;
}
