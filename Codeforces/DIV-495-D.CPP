#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define mx 1000005
int a[mx],cnt[mx];
vector< pair<int,int> >v;
void factorize(int t)
{
    for(int i=1; i*i<=t; i++){
        if(t%i==0){
            v.push_back(make_pair(i,t/i));
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin>>t;
    for(int i=1; i<=t; i++)cin>>a[i];

    sort(a+1,a+t+1);

    for(int i=1; i<=t; i++) cnt[a[i]]++;

    factorize(t);

    return 0;
}

