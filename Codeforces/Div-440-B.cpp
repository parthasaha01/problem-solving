#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
ll a[mx+5];
ll st[mx][25];
void create_st(int N)
{
    for(int i=0;i<N;i++){
        st[i][0]=i; //position of minimum value's from position i to 2^0=1 length
    }

    for(int j=1; (1<<j)<N; j++)
    {
        for(int i=0; i+(1<<j)-1<N; i++)
        {
            int x=st[i][j-1];
            int y=st[i+(1<<(j-1))][j-1];

            if(a[x]<=a[y]) st[i][j]=x;
            else st[i][j]=y;
        }
    }
}
ll RMQ(int i,int j)
{
    int k=(int)log2(j-i+1);
    int x=st[i][k];
    int y=st[j-(1<<k)+1][k];
    ll res =  min(a[x],a[y]);

    return res;
}
int main()
{
    ll n,k;
    scanf("%I64d %I64d",&n,&k);
    if(n<k)swap(n,k);
    ll maxx = -100000000005;
    ll minn = 100000000005;
    for(int i=0; i<n; i++)
    {
        scanf("%I64d",&a[i]);
        maxx = max(maxx,a[i]);
        minn = min(minn,a[i]);
    }

    if(k==1)
    {
        printf("%I64d\n",minn);
    }
    else if(k==2)
    {
        create_st(n);
        ll ans = -100000000005;
        for(int i=0; i<n-1; i++)
        {
            ll x1 = RMQ(0,i);
            ll x2 = RMQ(i+1,n-1);

            ll res = max(x1,x2);
            ans = max(ans,res);
        }

        printf("%I64d\n",ans);
    }
    else
    {
        printf("%I64d\n",maxx);
    }

    return 0;
}

