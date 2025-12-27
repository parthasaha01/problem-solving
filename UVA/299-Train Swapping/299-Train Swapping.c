#include<stdio.h>
int main()
{
    long int N,L,S,i,j,a,temp;

    scanf("%ld", &N);

    for(a=1; a <= N; a++ )
    {
        scanf("%ld", &L);
        long int ara[L];
        S=0;

        for(i=0; i<L; i++)
        {
            scanf("%ld", &ara[i]);
        }
        for(i=L-1; i>0; i--)
        {
            for(j=0; j<i; j++)
            {
                if(ara[j] > ara[j+1])
                {
                    temp=ara[j];
                    ara[j]=ara[j+1];
                    ara[j+1]=temp;
                    ++S;
                }
            }
        }
        printf("Optimal train swapping takes %ld swaps.\n",S);

    }

    return 0;
}
