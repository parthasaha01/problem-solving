#include<stdio.h>
int main()
{
    long int N,M,i,j,temp;

    while(scanf("%ld",&N)==1)
    {
        long int ara[N];
        M=0;
        for(i=0; i<N; i++)
        {
            scanf("%ld", &ara[i]);
        }
        for(i=N-1; i>0 ; i--)
        {
            for(j=0; j<i; j++)
            {
                if(ara[j] > ara[j+1])
                {
                    temp=ara[j];
                    ara[j]=ara[j+1];
                    ara[j+1]=temp;
                    ++M;
                }

            }
        }
        printf("Minimum exchange operations : %ld\n",M);
    }

    return 0;
}
