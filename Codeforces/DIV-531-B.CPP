#include<bits/stdc++.h>
using namespace std;
struct dt{
    int v,id;
}st[5005];
int a[5005],cnt[5005],ans[5005],col[5005];
bool cmp(dt x, dt y){
    if(x.v != y.v)return x.v<y.v;
    return x.id<y.id;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k;
    while(cin>>n>>k){
        memset(cnt,0,sizeof(cnt));
        memset(col,0,sizeof(col));
        for(int i=1; i<=n; i++){
            cin>>a[i];
            st[i].v = a[i];
            st[i].id = i;
        }

        sort(st+1,st+n+1,cmp);

        int flag = 1;
        for(int i=1; i<=n; i++){
            cnt[a[i]]++;
            if(cnt[a[i]]>k){
                flag = 0;
            }
        }

        if(flag==0){
            cout<<"NO"<<endl;
        }else{
            int cur = 0;
            int ase = 0;
            for(int i=1; i<=n; i++){
                cur++;
                ans[st[i].id] = cur;
                if(cur==k){
                    cur = 0;
                    ase = 1;
                }
            }

            if(ase==0){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
                for(int i=1; i<=n; i++){
                    if(i==n)cout<<ans[i]<<endl;
                    else cout<<ans[i]<<" ";
                }
            }
        }
    }
    return 0;
}

