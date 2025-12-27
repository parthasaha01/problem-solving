#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define Max 500000
#define HfMax 250000
#define sqt 707
long long num[Max];
void seive()
{
    long long i,j,doubleI,k,m;
    //long long sum;
    double x,y,sum;

    num[1]=1;
    num[2]=3;

    for(i=4; i<=Max; i+=2)
    {
        k=0;
        j=i;
        while((j&1)==0)
        {
            k++;
            j = j>>1;   // j = j/2
        }
        k++;
        sum = (1<<k)-1;
        //sum = pow(2,k)-1;
        num[i]=sum;
    }

    //printf("%lld\n",num[10]);

    for(i=3; i<=HfMax; i+=2)
    {
        if(num[i]==0)
        {
            num[i]=i+1;

            for(j=i+i; j<=Max; j+=i)
            {
                k=0;
                m=j;

                while((m%i)==0)
                {
                    k++;
                    m = m/i;   // j = j/2
                }
                k++;
                x=(double)i;
                y=(double)k;
                sum = (pow(x,y)-1)/(i-1);

                if(num[j] != 0)
                {
                    num[j] *= sum;
                }
                else
                {
                    num[j] = sum;
                }

            }
        }
    }
    //i=5,k=2;
    //sum = pow(10.0,28.0);
    //printf("%lf\n",sum);

}
int main()
{
    seive();

    long long T,n;

    scanf("%lld",&T);

    while(T--)
    {
        scanf("%lld",&n);

        printf("%lld\n",num[n]-n);
    }

    return 0;
}
