#include<stdio.h>
int main()
{
    long int t,a,b,i;

    scanf("%ld", &t);

    for(i=1; i <= t; i++)
    {
        scanf("%ld %ld",&a, &b);

        if(a>b)
        {
            printf(">\n");
        }
        else if(a<b)
        {
            printf("<\n");
        }
        else if(a == b)
        {
            printf("=\n");
        }
    }

    return 0;
}
