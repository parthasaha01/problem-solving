#include<bits/stdc++.h>
using namespace std;
#define mx 62505
int n,nn,lb,la,ls;
int I[mx],a[mx],b[mx],s[mx],vb[mx],ma[mx];
int LowerBound(int v)
{
    int lo=0;
    int hi=ls;
    int p=0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(I[md]<v)
        {
            lo=md+1;
            p=md+1;
        }
        else
        {
            hi=md-1;
        }
    }
    return p;
}
int lis()
{
    memset(vb,0,sizeof(vb));
    for(int i=1; i<=lb; i++)vb[b[i]]=1;

    memset(ma,0,sizeof(ma));
    for(int i=1,k=0; i<=la; i++){
        if(vb[a[i]]==1)
            ma[a[i]]=++k;
    }

    ls=0;
    for(int i=1; i<=lb; i++){
        if(ma[b[i]]!=0)
            s[++ls]=ma[b[i]];
    }

    I[0]=-1000000;
    for(int i=1; i<=ls; i++)I[i]=1000000;

    int ans=0;
    for(int i=1; i<=ls; i++)
    {
        int p = LowerBound(s[i]);
        I[p] = s[i];
        ans = max(ans,p);
    }
    return ans;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d%d",&n,&la,&lb);

        nn=n*n; la++; lb++;

        for(int i=1; i<=la; i++)scanf("%d",&a[i]);
        for(int i=1; i<=lb; i++)scanf("%d",&b[i]);

        int ans = lis();

        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}
/*
5

5 20 20
1 17 12 6 24 9 15 13 7 20 10 18 4 3 11 19 5 14 23 8 25
1 14 6 10 8 2 12 21 24 23 11 20 4 5 22 7 3 9 19 18 25

5 20 20
1 6 3 20 18 15 19 5 24 23 2 21 12 8 16 4 7 10 13 14 25
1 8 21 20 4 14 3 15 7 9 5 13 6 19 11 10 2 16 24 12 25

5 20 20
1 8 16 23 14 15 12 21 19 6 22 13 9 10 7 17 3 20 24 11 25
1 11 2 8 20 14 13 5 19 24 12 10 23 22 18 9 16 7 17 15 25

*/
