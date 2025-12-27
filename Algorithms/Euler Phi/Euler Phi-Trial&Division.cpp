#include<bits/stdc++.h>
using namespace std;
#define Mx 1000002
#define ll long long int
bool vis[Mx+5];
int phi[Mx+5];
vector<int>pr;
void sieve()
{
    pr.push_back(2);
    for(ll i=3; i<=Mx; i+=2){
        if(vis[i]==false){
            pr.push_back(i);
            for(ll j=i*i; j<=Mx; j+=2*i){
                vis[j]=true;
            }
        }
    }
}
int EulerPhi(int n)
{
    int ans=n;
    int sz=pr.size();
    for(int i=0; i<sz&&pr[i]*pr[i]<=n; i++)
    {
        if(n%pr[i]==0)
        {
            ans -= (ans/pr[i]);
            while(n%pr[i]==0){
                n /= pr[i];
            }
        }
    }
    if(n>1) ans -= ans/n;
    return ans;
}
int main()
{
    sieve();

    int n,T;

    cin >> T;
    while(T--)
    {
        cin >> n;
        cout << EulerPhi(n) << endl;
    }

    return 0;
}


