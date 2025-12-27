#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > ans;
vector<int>v,a;
int n,pr[50];
void sieve()
{
    for(int i=1; i<=35; i++)pr[i]=1;
    pr[1]=0;
    for(int i=2; i<=35; i++){
        if(pr[i]==1){
            for(int j=i+i; j<=35; j+=i){
                pr[j] = 0;
            }
        }
    }
}
void backtrack(int mask,int prev,vector<int> & v)
{
    if(mask==((1<<n)-1)){
        if(pr[prev+v[0]]){
            ans.push_back(v);
        }
        return;
    }
    for(int i=0; i<n; i++){
        if(((mask&(1<<i))==0) && (pr[prev+a[i]]==1)){
            v.push_back(a[i]);
            backtrack(mask|(1<<i),a[i],v);
            v.pop_back();
        }
    }
}
int main()
{
    sieve();

    int ks = 0;
    while(scanf("%d",&n)==1)
    {
        a.clear();
        for(int i=1; i<=n; i++)a.push_back(i);
        ans.clear();

        v.clear();
        v.push_back(1);

        backtrack(1,1,v);

        sort(ans.begin(),ans.end());

        if(ks)printf("\n");
        printf("Case %d:\n",++ks);
        for(int i=0; i<ans.size(); i++){
            for(int j=0; j<ans[i].size(); j++){
                if(j==n-1)printf("%d\n",ans[i][j]);
                else printf("%d ",ans[i][j]);
            }
        }
    }
    return 0;
}
