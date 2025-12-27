#include<stdio.h>
int main()
{
    int N,sum,a;
    while(scanf("%d", &N) != EOF)
    {
        if(N%2 == 0)
        {
            sum = (N/2)*3;
            printf("%d\n",sum);
        }
        else
        {
            sum = -2;
            a = ((N/2)+1)*3;
            sum += a;
            printf("%d\n",sum);
        }
    }

    return 0;
}
