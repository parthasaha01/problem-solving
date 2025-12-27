#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define Max 32000
#define sqt 178
int num[Max];
vector<int> primes;
void seive()
{
    int i,j,doubleI;
    primes.push_back(2);

    for(i=3; i<=sqt; i+=2)
    {
        if(num[i]==0)
        {
            primes.push_back(i);
            doubleI=i<<1;
            //num[i]=i;
            for(j=i*i; j<=Max; j+=doubleI)
            {
                num[i]=1;
            }
        }
    }
    for(i=sqt+1; i<=Max; i+=2)
    {
        if(num[i]==0)
        {
            primes.push_back(i);
        }
    }
}
int main()
{
    seive();

    long T,L,U,i,j,m,k,MaxDiv,div,sq,MaxNum;

    cin >> T;
    //psize=primes.size();

    while(T--)
    {
        cin >> L >> U;

        if(U==1)
        {
            cout << "Between 1 and 1, 1 has a maximum of 1 divisors." << endl;
            continue;
        }
        MaxDiv=2;

        if(L==1)
            MaxNum=2;
        else
            MaxNum=L;

        for(i=L; i<=U; i++)
        {
            div=1;
            m=i;
            sq=sqrt((double)i);

            for(j=0; primes[j]<=sq; j++)
            {
                if(m%primes[j]==0)
                {
                    k=0;
                    while(m%primes[j]==0)
                    {
                        k++;
                        m/=primes[j];
                    }
                    div *= (k+1);
                }

                if(m==1)
                    break;
            }

            if(m>1)
            {
                div *= 2;
            }

            if(div>MaxDiv)
            {
                MaxDiv=div;
                MaxNum=i;
            }
        }

        cout << "Between " << L << " and " << U << ", " << MaxNum << " has a maximum of " << MaxDiv << " divisors." << endl;
    }

    return 0;
}
