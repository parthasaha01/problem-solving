#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int ara[101][25];
int fac[101][25];
void factorization()
{
    int num,n,i,sq,j;

    for(num=2; num<=100; num++)
    {
        sq=sqrt(num);
        n=num;

        for(i=0; i<25; i++)
        {
            if((n%prime[i]) == 0)
            {
                while((n%prime[i] ) == 0)
                {
                    n = n/prime[i];
                    ara[num][i]++;
                }
            }
            if(n==1)
                break;
        }
    }

    /*for(i=2;i<=100;i++)
    {
        printf("%d = ",i);

        for(j=0;j<25;j++)
        {
            //if(ara[i][j]!=0)
            //{
                printf("%d ",ara[i][j]);
            //}
        }

        printf("\n\n");
    } */

}
void factorial()
{
    int i, j, x;

    for(i=2; i<=100; i++)
    {
        for(j=0; j<25; j++)
        {
            fac[i][j] = fac[i-1][j] + ara[i][j];
        }
    }

    /*for(i=2;i<=100;i++)
    {
        printf("%d = ",i);

        for(j=0;j<25;j++)
        {
            //if(ara[i][j]!=0)
            //{
                printf("%d ",fac[i][j]);
            //}
        }

        printf("\n\n");
    } */
}
int main()
{
    factorization();
    factorial();

    int N,i;

    while(scanf("%d",&N) && N)
    {
        printf("%3d! =",N);

        for(i=0;i<25;i++)
        {
            if(fac[N][i] != 0)
            {
                printf("%3d",fac[N][i]);

                if(i==14 && fac[N][i+1] != 0)
                {
                    printf("\n      ");
                }
            }
            else
            {
                break;
            }

        }
        printf("\n");

    }

    return 0;
}
