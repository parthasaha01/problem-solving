#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define Max 1000000
#define HMax 500000
#define sqt 1000
long int num[Max];
long int fac[Max];
void factors()
{
    long int i,j,k,m;
    num[2]=1;

    for(i=4; i<=Max; i+=2)
    {
        k=0;
        m=i;
        while((m&1)==0)
        {
            k++;
            m = m>>1;   // j = j/2
        }
        //k++;
        num[i]+=k;
    }
    for(i=3; i<=Max; i+=2)
    {
        if(num[i]==0)
        {
            num[i]=1;

            for(j=i+i; j<=Max; j+=i)
            {
                k=0;
                m=j;

                while((m%i)==0)
                {
                    k++;
                    m = m/i;   // j = j/2
                }
                //k++;

                num[j]+=k;
            }
        }
    }
}
void factorial()
{
    long int i;

    for(i=2;i<=Max;i++)
    {
        fac[i] = fac[i-1]+num[i];
    }
}
int main()
{
    factors();
    factorial();

    long int n;

    while(cin >> n)
    {
        cout << fac[n] << endl;
    }

    return 0;
}
