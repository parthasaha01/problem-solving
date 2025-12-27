#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int n,a[mx],cnt[mx],k,b[mx];

map<int,int>mp;
map<int,int>sp;
vector<int>vv;

int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        b[i] = a[i];
    }

    sort(b+1,b+n+1);

    k = 0;
    for(int i=1; i<=n; i++){

        if(mp.find(b[i])==mp.end()){
            mp[b[i]] = ++k;
            sp[k] = b[i];
        }
    }

    cnt[mp[a[n]]] = 1;
    int ans = 1;
    int pos = n;
    for(int i=n-1; i>=1; i--)
    {
        int id = mp[a[i]];
        int v = sp[id]+1;

        if(mp.find(v)!=mp.end())
        {
            cnt[mp[a[i]]] = max(cnt[mp[a[i]]], cnt[mp[v]]+1);
            if(cnt[mp[a[i]]]>ans){
                pos = i;
                ans = max(ans,cnt[mp[a[i]]]);
            }

        }
        else{
            cnt[mp[a[i]]] = 1;
        }
    }

    int need = a[pos];
    int maxx = ans;
    for(int i=pos; i<=n; i++)
    {
        if(cnt[mp[a[i]]]==maxx && a[i]==need){
            vv.push_back(i);
            maxx--;
            need = need+1;
        }
    }

    //ans = vv.size();
    printf("%d\n",ans);


    int xx = vv.size();
    for(int i=0; i<xx; i++){
        if(i==xx-1){
            printf("%d\n",vv[i]);
        }
        else{
            printf("%d ",vv[i]);
        }
    }

    return 0;
}

