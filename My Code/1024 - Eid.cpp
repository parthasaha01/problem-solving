#include<bits/stdc++.h>
using namespace std;
int vis[10005];
vector<int>pr,vv;
int cnt[10005],ar[1005];
string lcm;
void multiply(int v)
{
    // a contains the biginteger in reversed form
    int carry = 0;
    for( int i = 0; i < lcm.size(); i++ )
    {
        carry += (lcm[i] - 48) * v;
        lcm[i] = ( carry % 10 + 48 );
        carry /= 10;
    }
    while( carry )
    {
        lcm += ( carry % 10 + 48 );
        carry /= 10;
    }
}
void sieve()
{
    pr.push_back(2);
    for(int i=3; i<=10000; i+=2)
    {
        if(vis[i]==0)
        {
            pr.push_back(i);
            for(int j=i*i; j<=10000; j+=2*i)
            {
                vis[j]=1;
            }
        }
    }
}
void factorization(int n)
{
    for(int i=0; pr[i]*pr[i]<=n && i<pr.size(); i++)
    {
        int k=0;
        while(n%pr[i]==0)
        {
            k++;
            n /= pr[i];
        }

        cnt[pr[i]] = max(cnt[pr[i]],k);
    }

    if(n>1)
    {
        cnt[n] = max(cnt[n],1);
    }
}
int main()
{
    sieve();

    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);

        memset(cnt,0,sizeof(cnt));

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&ar[i]);
            factorization(ar[i]);
        }

        vv.clear();

        for(int i=0; i<pr.size(); i++)
        {
            if(cnt[pr[i]]>0)
            {
                int uu = 1;
                for(int k=1; k<=cnt[pr[i]]; k++)
                {
                    uu *= pr[i];
                }

                vv.push_back(uu);
            }
        }

        lcm = "1";

        for(int i=0; i<vv.size(); i++)
        {
            multiply(vv[i]);
        }

        reverse(lcm.begin(),lcm.end());

        printf("Case %d: ",ks);
        cout << lcm << endl;
    }

    return 0;
}
