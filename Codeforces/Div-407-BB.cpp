#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll a[mx+5],b,q,l;
int m;
int fun(ll v)
{
    int lo  = 1;
    int hi  = m;
    while(lo<=hi)
    {
        ll md = (lo+hi)/2;
        if(a[md]==v){
            return 1;
        }
        else if(a[md]<v){
            lo = md+1;
        }
        else hi=md-1;
    }
    return 0;
}
int main()
{
    //map<ll,ll>mp
    //scanf("%I64d%I64d%I64d%I64d",&b,&q,&l,&m);
    cin>>b>>q>>l>>m;

    for(ll i=1; i<=m; i++)
    {
        scanf("%I64d",&a[i]);
        //mp[a[i]]=1;
    }

    sort(a+1,a+m+1);

    if(b==0)
    {
        if(fun(0)==1){
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
        if(fun(b)==1 && fun(0)==1)
        {
            printf("0\n");
        }
        else if(fun(b)==0 && fun(0)==1){
            if(abs(b)<=l)printf("1\n");
            else printf("0\n");
        }
        else if(fun(b)==1 && fun(0)==0){
            printf("inf\n");
        }
        else{
            printf("inf\n");
        }

        return 0;
    }

    if(q==1)
    {
        if(fun(b)==1)printf("0\n");
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
            if(fun(b)==1 && fun(b1)==1){
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
        if(fun(bb)==0)ans++;
        bb = bb*q;
    }

    printf("%I64d\n",ans);

    return 0;
}

