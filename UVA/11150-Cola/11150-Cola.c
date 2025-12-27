#include<stdio.h>
int main()
{
    int n,sum,i;

    while(scanf("%d", &n) != EOF)
    {
        if(n % 2 != 0)
        {
            sum = -2;
            for(i=1; i <= n; i+=2)
            {
                sum += 3;
            }
        }
        else
        {
            sum = 0;
            for(i=2; i <= n; i+=2)
            {
                sum += 3;
            }
        }
        printf("%d\n",sum);
    }

    return 0;
}
