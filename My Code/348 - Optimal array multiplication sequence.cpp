#include<bits/stdc++.h>
using namespace std;
#define pii pair <ll,ll>
#define ll long long
vector<pii>vv;
ll n,r[15],c[15],dp[15][15],a[15],g[15];
ll fun(ll b,ll e)
{
    if(b>=e)return 0;
    if(dp[b][e]!=-1)return dp[b][e];
    ll ret = 10000000000000000;
    for(ll m=b; m<e; m++){
        ll sum = fun(b,m)+fun(m+1,e)+(r[b]*c[m]*c[e]);
        ret = min(ret,sum);
    }
    return dp[b][e]=ret;
}
void path(ll b,ll e)
{
    if(b>=e)return;

    ll ret = fun(b,e);

    for(ll m=b; m<e; m++){
        ll sum = fun(b,m)+fun(m+1,e)+(r[b]*c[m]*c[e]);
        if(sum==ret){
            pii pp;
            pp = make_pair(b,m);
            if(b!=m)vv.push_back(pp);
            //vv.push_back(pp);
            pp = make_pair(m+1,e);
            if(m+1!=e)vv.push_back(pp);
            //vv.push_back(pp);
            path(b,m);
            path(m+1,e);
            break;
        }
    }
}
int main()
{
    int ks=0;

    while(scanf("%lld",&n) && n)
    {
        for(int i=1; i<=n; i++){
            scanf("%lld%lld",&r[i],&c[i]);
        }

        memset(dp,-1,sizeof(dp));
        ll ans = fun(1,n);
        //printf("ans=%d\n",ans);

        path(1,n);

        char ss[500];
        for(int i=0; i<400; i++)ss[i]='.';

        int k=0;
        for(int i=1; i<400; i++)
        {
            if(i%30==0){
                ss[i-1]=' ';
                ss[i] = 'x';
                ss[i+1] = ' ';
                i++;
            }
            else if(i%15==0){
                ss[i]='A';
                i++;k++;
                if(k<10) ss[i]=k + '0';
                if(k>=10){
                    ss[i]=(k/10) + '0';
                    i++;
                    ss[i]=(k%10) + '0';
                }
                a[k] = i;
            }
            else{
               ss[i]='.';
            }
        }
        ss[450]='/0';
        for(int i=0; i<vv.size(); i++)
        {
            int x = vv[i].first;
            int y = vv[i].second;
            //printf("(%d %d)\n",x,y);
            for(int j=a[x]-1; j>=0; j--){
                if(ss[j]=='.'){
                    ss[j]='(';
                    break;
                }
            }
            for(int j=a[y]+1; j<400; j++){
                if(ss[j]=='.'){
                    ss[j]=')';
                    break;
                }
            }

        }
        vv.clear();

        string s; s="";
        s+='(';
        k=0;
        for(int i=0; i<400; i++){

            if(ss[i+1]=='x')k++;
            if(k==n)break;
            if(ss[i]!='.')s+=ss[i];
        }
        s+=')';

        printf("Case %d: ",++ks);
        cout << s << endl;
    }
    return 0;
}
