#include<stdio.h>
int main()
{
    int i,j,k,n,a,b,c,T;
    scanf("%d",&T);
    for(c=1; c<=T; c++)
    {
        scanf("%d %d",&n,&a);
        for(b=1; b<=a; b++)
        {
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=i; j++)
                {
                    printf("%d",i);
                }
                printf("\n");
            }
            for(i=n-1; i>=1; i--)
            {
                for(k=i; k>=1; k--)
                {
                    printf("%d",i);
                }
                printf("\n");
            }

            if(b<a) printf("\n");
        }

        if(c<T) printf("\n");
    }

    return 0;
}
