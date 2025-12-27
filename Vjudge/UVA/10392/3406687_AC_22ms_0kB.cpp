#include<bits/stdc++.h>
using namespace std;
#define mx 1000000
#define sq 1000
bool check[mx];
vector<long long>prime;
void seive()
{
    long long i,j;
    prime.push_back(2);

    for(i=3; i<=sq; i+=2){
        if(!check[i]){
            prime.push_back(i);
            for(j=i*i; j<=mx; j+=(i+i))
                check[j]=true;
        }
    }
    for(i=sq+1; i<=mx; i+=2){
        if(!check[i])
            prime.push_back(i);
    }
}
int main()
{
    seive();
    long long n,i,sz;
    sz=prime.size();
    while(cin >> n && n>=0)
    {
        for(i=0; prime[i]<=sqrt(n) && i<sz; i++)
        {
            while(n%prime[i]==0)
            {
                printf("    %lld\n",prime[i]);
                n/=prime[i];
            }
        }
        if(n>1)
            printf("    %lld\n",n);
        cout << endl;
    }

    return 0;
}
