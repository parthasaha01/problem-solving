#include<bits/stdc++.h>
using namespace std;
vector<int>uu[50005],vv;
int vis[50005],cnt[50005];
int a[1005];
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);

        int gcd  = 0;
        memset(vis,0,sizeof(vis));
        vv.clear();

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            if(vis[a[i]]==0){
                vv.push_back(a[i]);
            }
            vis[a[i]]=1;
            gcd = __gcd(gcd,a[i]);
        }

        if(gcd==1){
            printf("0\n");
            continue;
        }

        int ans = n-(int)vv.size();
        int k = vv.size();

        sort(vv.begin(),vv.end());

        for(int i=0; i<k; i++){
            for(int j=i+1; j<k; j++){
                //if(i==j)continue;
                if(__gcd(vv[i],vv[j])!=1){
                    uu[vv[i]].push_back(vv[j]);
                    uu[vv[j]].push_back(vv[i]);
                }
            }

        }
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<k; i++){
            cnt[vv[i]] = uu[vv[i]].size();
        }
        memset(vis,0,sizeof(vis));
        for(int p=0; p<k; p++)
        {
            int maxx = 0;
            int v=0;
            for(int i=0; i<k; i++)
            {
                if(vis[vv[i]]==1)continue;
                int sz = cnt[vv[i]];
                if(sz>maxx){
                    maxx = sz;
                    v = vv[i];
                }
            }

            //printf("partha\n");
            if(maxx==0){
                //printf("partha1\n");
                break;
            }

            for(int i=0; i<uu[v].size(); i++){
                int x = uu[v][i];
                if(vis[x]==1)continue;
                cnt[x]--;
            }

            ans++;
            vis[v]=1;
        }

        int g = 0;
        for(int i=0; i<k; i++)
        {
            //cout << (*it) << endl;
            if(vis[vv[i]]==1)continue;
            g = __gcd(g,vv[i]);
            //ss[*it].clear();
        }

       // cout << g << endl;

        if(g!=1)ans=-1;

        printf("%d\n",ans);


        for(int i=0; i<k; i++){
            uu[vv[i]].clear();
        }

    }

    return 0;
}

