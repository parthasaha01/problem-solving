#include<stdio.h>
int main()
{
    int T, n, a, b;

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &n);

        if(n > 10)
        {
            a = n-10;
            b = n-a;
        }
        else
        {
            b=n;
            a=0;
        }

        printf("%d %d\n", a, b);

    }

    return 0;
}
