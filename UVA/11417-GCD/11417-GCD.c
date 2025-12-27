#include<stdio.h>
int main()
{
    long int GCD,N,i,j,a,b,temp;

    while(scanf("%ld",&N)==1 && N != 0)
    {
        GCD=0;
        for(i=1; i<N; i++)
        {
            for(j=i+1; j<=N; j++)
            {
                a=i;
                b=j;
                while(b!=0)
                {
                    temp=b;
                    b=a%b;
                    a=temp;
                }
                GCD += a;
            }
        }
        printf("%ld\n",GCD);
    }

    return 0;
}
