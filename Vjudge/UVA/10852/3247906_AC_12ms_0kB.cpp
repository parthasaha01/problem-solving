#include<bits/stdc++.h>
using namespace std;

long long int N = 200005, status[200005],prime[200005],jog[200005],l;

void sieve(void)
{
    long long int i,j,sqrtN;
    l=1;
    status[1]=1;
    prime[0]=2;



    for( i = 2; i <= N; i++ ) status[i] = 0;

    for(i=4; i<=N; i+=2)
    {
        if(i%2==0)

            status[i]=1;
    }
    sqrtN = int( sqrt((double) N ));

    for( i = 3; i <= sqrtN; i += 2 )
    {

        if( status[i] == 0 )
        {



            for(  j = i * i; j <= N; j += i + i )

                status[j] = 1;
        }

    }

    for( i = 3; i <= N; i +=2 )
    {

        if( status[i] == 0 )
        {
            prime[l]=i;
            l++;

        }

    }

}

int main()
{


    long long int a,b,c,d,i,j,k=1,m,n,o,p,sum,res,count,temp,flag;
    sieve();


   scanf("%lld",&a);

    for(i=1;i<=a;i++)
    {

        scanf("%lld",&n);
        for(j=2;j<=n;j++)
        {
            if(status[j]==0)
            {
                if(2*j>n)
                {
                    printf("%lld\n",j);
                    break;
                }
            }
        }
    }

}
