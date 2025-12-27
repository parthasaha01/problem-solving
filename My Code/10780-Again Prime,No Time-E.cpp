#include<bits/stdc++.h>
using namespace std;
#define mx 10005
bool flag[mx+5];
vector<int>pr,fr;
int vm[mx+5],vn[mx+5];
void sieve()
{
    pr.push_back(2);
    for(int i=3; i<=mx; i+=2){
        if(!flag[i]){
            pr.push_back(i);
            for(int j=i*i; j<=mx; j+=2*i) flag[j]=true;
        }
    }
}
int factorization(int n,int p)
{
    int cnt=0;
    for(int i=p; i<=n; i*=p){
        cnt += (n/i);
    }
    return cnt;
}
int main()
{
    sieve();

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int m,n; scanf("%d%d",&m,&n);

        memset(vn,0,sizeof(vn));
        memset(vm,0,sizeof(vm));
        fr.clear();

        for(int i=0; i<pr.size() && pr[i]<=n; i++){
            int cnt = factorization(n,pr[i]);
            vn[pr[i]]=cnt;
        }

        for(int i=0; i<pr.size() && pr[i]*pr[i]<=m; i++){
            int cnt = 0;
            while(m%pr[i]==0){
                cnt++;
                m/=pr[i];
            }
            vm[pr[i]]=cnt;
            if(cnt)fr.push_back(pr[i]);
        }
        if(m>1)vm[m]=1;
        if(m>1)fr.push_back(m);

        int ans=100000000;

        for(int i=0; i<fr.size(); i++){
            ans = min(ans,vn[fr[i]]/vm[fr[i]]);
        }

        printf("Case %d:\n",ks);
        if(ans)printf("%d\n",ans);
        else printf("Impossible to divide\n");
    }
    return 0;
}
