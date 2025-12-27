#include<bits/stdc++.h>
using namespace std;
//vector<int>uu[1005],vv;
unordered_set<int>ss;
int vis[1002],cnt[1002];
int uu[1002][1002],vv[1002];
int a[1002];
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);

        int gcd  = 0;
       // memset(vis,0,sizeof(vis));
        //vv.clear();
        ss.clear();

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            ss.insert(a[i]);
            gcd = __gcd(gcd,a[i]);
        }

        if(gcd==1){
            printf("0\n");
            continue;
        }

        memset(vis,0,sizeof(vis));

        int k=0;
        unordered_set<int> :: iterator it;
        for(it=ss.begin(); it!=ss.end(); it++)
        {
            vv[k++] = *it;
        }

        int ans = n-k;
        //sort(vv.begin(),vv.end());
        memset(cnt,0,sizeof(cnt));

        for(int i=0; i<k; i++){
            for(int j=i+1; j<k; j++){
                //if(i==j)continue;
                if(__gcd(vv[i],vv[j])!=1){
                    uu[i][cnt[i]++]=j;
                    uu[j][cnt[j]++]=i;
                }
            }

        }

//        for(int i=0; i<k; i++){
//            cnt[i] = uu[i].size();
//        }
        memset(vis,0,sizeof(vis));
        for(int p=0; p<k; p++)
        {
            int maxx = 0;
            int v=0;
            for(int i=0; i<k; i++)
            {
                if(vis[i]==1)continue;
                int sz = cnt[i];
                if(sz>maxx){
                    maxx = sz;
                    v = i;
                }
            }

            //printf("partha\n");
            if(maxx==0){
                //printf("partha1\n");
                break;
            }

            for(int i=0; i<cnt[v]; i++){
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
            if(vis[i]==1)continue;
            g = __gcd(g,vv[i]);
            //ss[*it].clear();
        }

       // cout << g << endl;

        if(g!=1)ans=-1;

        printf("%d\n",ans);


//        for(int i=0; i<k; i++){
//            uu[i].clear();
//        }

    }

    return 0;
}


