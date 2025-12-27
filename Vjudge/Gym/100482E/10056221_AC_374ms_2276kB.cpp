#include<bits/stdc++.h>
using namespace std;
#define MOD 1013
#define ll long long
string ss,pp;
int sum[15][1050],cc,n,ar[15],sz;
ll dp[15][1050];
bool flag;
void calc(int x,int y,int id)
{
    for(int v=0; v<1013; v++)
    {
        int code=v;
        for(int i=x; i<=y; i++)
        {
            int d = ss[i];
            code = ((code*31)+d)%MOD;
        }
        sum[id][v] = code;
    }
}
ll fun(int pos,int code)
{
    if(pos>n)
    {
        if(code==cc)return 1;
        return 0;
    }

    if(dp[pos][code]!=-1)return dp[pos][code];

    ll ret = 0;
    for(int d='a'; d<='z'; d++)
    {
        int vv = ((code*31)+d)%MOD;
        int uu;

        if(pos==n)
        {
            if(ar[pos]==sz-1)
            {
                uu = vv;
            }
            else
            {
                uu = sum[pos+1][vv];
            }
        }
        else
        {
            if(ar[pos+1]==ar[pos]+1)
            {
                uu = vv;
            }
            else
            {
                uu = sum[pos+1][vv];
            }
        }

        ret += fun(pos+1,uu);
    }

    return dp[pos][code] = ret;
}
void path(int pos,int code)
{
    if(pos>n)
    {
        //if(code==cc)return 1;
        return;
    }

    //if(dp[pos][code]!=-1)return dp[pos][code];

    ll ret = 0;
    ll ww = fun(pos,code);
    for(int d='a'; d<='z'; d++)
    {
        int vv = ((code*31)+d)%MOD;
        int uu;

        if(pos==n)
        {
            if(ar[pos]==sz-1)
            {
                uu = vv;
            }
            else
            {
                uu = sum[pos+1][vv];
            }
        }
        else
        {
            if(ar[pos+1]==ar[pos]+1)
            {
                uu = vv;
            }
            else
            {
                uu = sum[pos+1][vv];
            }
        }

        ret += fun(pos+1,uu);

        if(ret==ww)
        {
            pp[ar[pos]]=d;
            path(pos+1,uu);
            break;
        }
    }
}
int main()
{
    int tt;
    scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&cc);

        cin>>ss;
        sz = ss.size();

        pp = ss;

        for(int i=0; i<15; i++)
        {
            for(int j=0; j<1013; j++)
            {
                sum[i][j]=1;
            }
        }

        int k=1;
        int cnt=0;

        for(int i=0; i<sz; i++)
        {
            if(ss[i]!='?')
            {
                int j=i;
                while(j+1<sz && ss[j+1]!='?')
                {
                    j++;
                }
                calc(i,j,k);
                i=j;
            }
            else
            {
                k++;
                cnt++;
                ar[cnt]=i;
            }
        }

        if(ss[sz-1]=='?')
        {
            flag==true;
        }

        n=cnt;
        ll ans;

        memset(dp,-1,sizeof(dp));

        if(ss[0]=='?')
        {
            ans = fun(1,0);
        }
        else
        {
            ans = fun(1,sum[1][0]);
        }

        if(ans==1)
        {
            //printf("Case #%d: %d\n",ks,ans);

            if(ss[0]=='?')
            {
                path(1,0);
            }
            else
            {
                path(1,sum[1][0]);
            }

            printf("Case #%d: ",ks);
            cout << pp << endl;
        }
        else
        {
            printf("Case #%d: %lld\n",ks,ans);
        }

    }
    return 0;
}
