#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int n,k,a[2005],pos[2005];
vector<int>vv;
struct dt{
    int v,p;
}b[2005];
bool cmp(dt x,dt y){
    if(x.v==y.v)return x.p<y.p;
    return x.v>y.v;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        b[i].v=a[i];
        b[i].p=i;
    }

    sort(b+1,b+n+1,cmp);

    memset(pos,0,sizeof(pos));
    int maxx = 0;
    for(int i=1; i<=k; i++){
        maxx+=b[i].v;
        pos[b[i].p]=1;
    }

    vv.clear();
    int cur = 1;
    for(int i=1; i<=n; i++){
        if(pos[i]==1){
            int d = i-cur+1;
            if((int)vv.size()==k-1){
                d = n-cur+1;
                vv.push_back(d);
                break;
            }
            else{
                vv.push_back(d);
                cur = i+1;
            }
        }
    }

    cout<<maxx<<endl;
    for(int i=0; i<k; i++){
        if(i==k-1)cout<<vv[i]<<endl;
        else cout<<vv[i]<<" ";
    }

    //main();

    return 0;
}
