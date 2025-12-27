#include<stdio.h>
int main()
{
    long int n,h,k,i,j=0,sum;

    while(scanf("%ld", &n)==1 && n != 0)
    {
        long int ara[n];
        sum=0;

        for(i=0; i<n; i++)
        {
            scanf("%ld", &ara[i]);
            sum += ara[i];
        }
        h = sum/n;

            k=0;
            j++;
            for(i=0; i<n; i++)
            {
                if(ara[i] > h)
                {
                    k += (ara[i]-h);
                }
            }
            printf("Set #%ld\n",j);
            printf("The minimum number of moves is %ld.\n\n",k);
    }

    return 0;
}
