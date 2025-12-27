#include<bits/stdc++.h>
using namespace std;
#define mx 1000000
#define ll long long
bool flag[mx];
vector<ll>pr;
void seive()
{
    pr.push_back(2);
    for(ll i=3; i<=mx; i+=2){
        if(!flag[i]){
            pr.push_back(i);
            for(ll j=i*i; j<=mx; j+=(i+i))
                flag[j]=true;
        }
    }
}
int main()
{
    seive();
    ll n;

    while(cin>>n && n>=0)
    {
        vector<ll>fr;
        for(int i=0; i<pr.size() && pr[i]*pr[i]<=n; i++){
            while(n%pr[i]==0){
                fr.push_back(pr[i]);
                n/=pr[i];
            }
        }
        if(n>1) fr.push_back(n);
        for(int i=0; i<fr.size(); i++)
            printf("    %lld\n",fr[i]);
        printf("\n");
    }
    return 0;
}