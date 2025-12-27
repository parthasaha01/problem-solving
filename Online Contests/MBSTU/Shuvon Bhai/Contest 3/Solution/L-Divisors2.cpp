#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define Max 1000000
#define HfMax 500000
#define sqt 1000
long int num[Max];
long int value[Max];
long int result[Max];
int primediv[300];
int ara[]={29,20,12,7,1};
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113};
long int i,j,k,m;
void NumberOfDivisors()
{
    num[1]=1;
    value[1]=1;

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
        //sum = pow(2,k)-1;
        value[i]=k;
    }

    for(i=3; i<=HfMax; i+=2)
    {
        if(num[i]==0)
        {
            value[i]=2;

            for(j=i+i; j<=Max; j+=i)
            {
                num[j]=1;
                k=0;
                m=j;

                while((m%i)==0)
                {
                    k++;
                    m = m/i;   // j = j/2
                }
                k++;

                if(value[j] != 0)
                {
                    value[j] *= k;
                }
                else
                {
                    value[j] = k;
                }

            }
        }
    }
}

void divisors()
{
    // maximum number of divisors is 240

    //printf("partha\n");

    k=0;

    for(i=0;i<6;i++)
    {
        j=i+1;
        for(k=0; k<ara[i]; k++)
        {
            m=prime[i]*prime[j];
            primediv[m]=1;
            j++;
        }
    }

    /*for(i=0; i<300; i++)
    {
        if(primediv[i]==1)
            printf("%d ",i);
    } */

    k=0;

    for(i=1;i<=Max;i++)
    {
        if(primediv[value[i]]==1)
        {
            result[k]=i;
            k++;
        }
    }
}

int main()
{
    NumberOfDivisors();
    divisors();

    /*for(i=1;i<=100;i++)
    {
        printf("%ld ",value[i]);
    }

    printf("\n"); */

    for(i=8;i<k;i+=9)
    {
        printf("%ld\n",result[i]);
    }

    return 0;
}
