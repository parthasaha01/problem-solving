#include<bits/stdc++.h>
using namespace std;
struct dt{int v,i;};
dt a[101];
int n,vis[101],ans[101];
vector<int>vv[101];
bool cmp(dt x,dt y){
    if(x.v==y.v)return x.i<y.i;
    return x.v>y.v;
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++){
        int v; cin>>v;
        a[i].v=v; a[i].i=i;
    }

    sort(a+2,a+n+1,cmp);

//    for(int i=1; i<=n; i++){
//        cout<<a[i].i<<" "<<a[i].v<<endl;
//    }

    vis[1]=1;
    for(int i=1,j=1; i<=n&&j<n; i++){
        if(vis[i]==0)break;
        for(int k=1; k<=a[i].v&&j<n; k++) {
            vis[++j]=i;
            vv[a[i].i].push_back(a[j].i);
        }
    }

    int f=1;
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            f = 0; break;
        }
    }

    if(!f)cout<<-1<<endl;
    else{
        cout<<n-1<<endl;
        for(int i=1; i<=n; i++){
            for(int k=0; k<vv[a[i].i].size(); k++){
                cout<<a[i].i<<" "<<vv[a[i].i][k]<<endl;
            }
        }
    }

    return 0;
}
