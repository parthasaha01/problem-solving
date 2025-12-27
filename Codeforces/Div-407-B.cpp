#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll a[mx+5];
int main()
{
    map<ll,ll>mp;
    ll b,q,l,m;
    scanf("%I64d%I64d%I64d%I64d",&b,&q,&l,&m);

    if(abs(b)>l){printf("0\n"); return 0;}

    for(ll i=1; i<=m; i++)
    {
        scanf("%I64d",&a[i]);
        mp[a[i]]=1;
    }

    if(b==0)
    {
        if(mp[0]==1){
            printf("0\n");
        }
        else{
            if(abs(b)<=l)printf("inf\n");
            else printf("0\n");
        }
        return 0;
    }

    if(q==0)
    {
        if(mp[b]==1 && mp[0]==1)
        {
            printf("0\n");
        }
        else if(mp[b]==0 && mp[0]==1){
            if(abs(b)<=l)printf("1\n");
            else printf("0\n");
        }
        else if(mp[b]==1 && mp[0]==0){
            printf("inf\n");
        }
        else{
            printf("inf\n");
        }

        return 0;
    }

    if(q==1)
    {
        if(mp[b]==1)printf("0\n");
        else{
            if(abs(b)<=l)printf("inf\n");
            else printf("0\n");
        }

        return 0;
    }

    if(q==-1)
    {
        if(abs(b)<=l){
            ll b1 = -b;
            if(mp[b]==1 && mp[b1]==1){
                printf("0\n");
            }
            else{
                printf("inf\n");
            }
        }
        else{
            printf("0\n");
        }

        return 0;
    }

    ll bb = b;
    ll ans = 0;
    while(abs(bb)<=l)
    {
        if(mp[bb]==0)ans++;
        bb = bb*q;
    }

    printf("%I64d\n",ans);

    return 0;
}
