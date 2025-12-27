#include<bits/stdc++.h>
using namespace std;
#define N 3000
#define sqN 54
int result[2000];
int prime[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
void seive()
{
    int i,j,Count=0,n,k,sq;

    for(j=6;j<=N;j++)
    {
        k=0;
        n=j;
        //sq=sqrt((double)n);

        for(i=0; i<16; i++)
        {
            if( (n%prime[i] ) == 0)
            {
                k++;
                //factor[k++] = prime[i];
                while((n%prime[i] ) == 0)
                {
                    n /= prime[i];
                    //printf("while\n");

                }
            }
        }
        if(n>1)
        {
            k++;
            //factor[k++] = n;
        }

        if(k==2)
        {
            result[j]=++Count;
        }
        else
        {
            result[j]=Count;
        }

        //printf("for\n");

    }
}
int main()
{
    seive();
    int num;

    //printf("main\n");

    while(scanf("%d",&num)==1)
    {
        printf("%d\n",result[num]);

    }

    return 0;
}
