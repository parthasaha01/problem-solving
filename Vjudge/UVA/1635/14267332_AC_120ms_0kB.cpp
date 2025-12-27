#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int vis[31630];
vector<int>pr;
vector<int>ans;
vector< pair<int,int> > fac;
int ret[15];
void sieve()
{
    pr.push_back(2);
    for(int i=3; i<=31625; i+=2){
        if(vis[i]==0){
            pr.push_back(i);
            for(int j=i*i; j<=31625; j+=i+i){
                vis[j]=1;
            }
        }
    }
}
void factorize(int m)
{
    fac.clear();
    for(int i=0; i<pr.size() && pr[i]*pr[i]<=m; i++){
        if(m%pr[i]==0){
            int k = 0;
            while(m%pr[i]==0){
                m/=pr[i];
                k++;
            }
            fac.push_back(make_pair(pr[i],k));
        }
    }
    if(m>1)fac.push_back(make_pair(m,1));
}
void add(int lob)
{
    for(int i=0; i<fac.size(); i++){
        int base = fac[i].first;
        int k = 0;
        while(lob%base==0){
            ++k;
            lob/=base;
        }
        ret[i]+=k;
    }
}
void remov(int hor)
{
    for(int i=0; i<fac.size(); i++){
        int base = fac[i].first;
        int k = 0;
        while(hor%base==0){
            ++k;
            hor/=base;
        }
        ret[i]-=k;
    }
}
int check()
{
    for(int i=0; i<fac.size(); i++){
        int power = fac[i].second;
        if(ret[i]<power)return 0;
    }
    return 1;
}
void solve(int n)
{
    int ncr = 1;
    memset(ret,0,sizeof(ret));
    ans.clear();
    for(int r=1; r<=n; r++){
        int lob = n-r+1;
        int hor = r;
        add(lob);
        remov(hor);

        if(check())ans.push_back(r+1);
    }
}
int main()
{
    sieve();
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        factorize(m);
        solve(n-1);
        int k = ans.size();
        printf("%d\n",k);
        for(int i=0; i<k; i++){
            if(i==k-1)printf("%d",ans[i]);
            else printf("%d ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
