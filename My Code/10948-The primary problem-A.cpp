#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000005
bool flag[mx+5];
vector<int>pr;
void sieve()
{
    flag[0]=flag[1]=true;
    for(ll i=2; i<=mx; i++){
        if(!flag[i]){
            pr.push_back(i);
            for(ll j=i*i; j<=mx; j+=i){
                flag[j]=true;
            }
        }
    }
}
int main()
{
    sieve();

    int n;
    while(scanf("%d",&n) && n)
    {
        printf("%d:\n",n);

        bool paisi=false;
        for(int i=0; i<pr.size() && pr[i]<=(n/2); i++){
            if(!flag[n-pr[i]]){
                printf("%d+%d\n",pr[i],n-pr[i]);
                paisi=true;
                break;
            }
        }

        if(!paisi) printf("NO WAY!\n");

    }

    return 0;
}
