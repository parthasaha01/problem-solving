#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int kcnt[mx],cnt[mx],res[mx],a[mx];
vector<int>v;
int main()
{
    int n,k;

    while(scanf("%d%d",&n,&k)==2)
    {
        memset(kcnt,0,sizeof(kcnt));
        memset(cnt,0,sizeof(cnt));

        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }

        v.push_back(a[0]);
        kcnt[a[0]]++;
        for(int i=1; i<n; i++){
            if(a[i]!=a[i-1]){
                v.push_back(a[i]);
                kcnt[a[i]]++;
            }
        }

        int sz = v.size();

        for(int i=1; i<sz-1; i++){
            if(v[i-1]==v[i+1]){
                cnt[v[i]]++;
            }
        }

        for(int i=1; i<=k; i++){
            res[i] = sz-kcnt[i]-1-cnt[i];
        }

        int minn = 1000000000;
        int ans;
        for(int i=1; i<=k; i++){
            if(res[i]<minn){
                ans=i;
                minn=res[i];
            }
        }

        printf("%d\n",ans);
        v.clear();
    }

    return 0;
}
