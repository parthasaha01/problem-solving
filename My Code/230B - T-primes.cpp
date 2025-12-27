#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1000000;
int isprime[MAXN+5];
void sieve()
{
    for(int i=2; i<=MAXN; i++)isprime[i]=1;
    for(int i=2; i<=MAXN; i++){
        if(isprime[i]){
            for(int j=i+i; j<=MAXN; j+=i){
                isprime[j]=0;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    sieve();
    int t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        ll sq = sqrt(n);
        if(sq*sq != n || !isprime[sq])cout<<"NO"<<endl;
        else cout << "YES" << endl;
    }
    return 0;
}
