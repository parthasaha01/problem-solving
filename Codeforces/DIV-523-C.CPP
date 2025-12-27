#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007LL;
int n,a[100005];
ll ans = 0, tree[100005];

void divisor(int x){
    int val = a[x];
    int sq = sqrt(val);
    vector<int>v;
    for(int i=1; i<=sq; i++){
        if(a[x]%i==0){
            if(i<=n)v.push_back(i);
            if((a[x]/i)!=i){
                if((a[x]/i)<=n)v.push_back(a[x]/i);
            }
        }
    }

    sort(v.begin(),v.end());

    for(int i=0; i<v.size(); i++){
        int d = v[i];
        if(d>x)continue;
        if(d==1){
            //tree[d]++;
            ans++;
            ans %= mod;
        }else{
            if(tree[d-1]>0){
                ans += tree[d-1];
                ans %= mod;
                //tree[d] += tree[d-1];
            }
        }
    }



    for(int i=v.size()-1; i>=0; i--){
        int d = v[i];
        if(d>x)continue;
        if(d==1){
            tree[d]++;
            tree[d] %= mod;
            //ans++;
        }else{
            if(tree[d-1]>0){
                //ans += tree[d-1];
                tree[d] += tree[d-1];
                tree[d] %= mod;
            }
        }
    }

//    cout<<x<<":"<<endl;
//    for(int i=1; i<=n; i++){
//        cout<<i<<" "<<tree[i]<<endl;
//    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    for(int i=1; i<=n; i++){
        divisor(i);
    }

//    for(int i=1; i<=n; i++){
//        cout<<i<<" "<<tree[i]<<endl;
//    }

    cout << ans << endl;

    //main();
    return 0;
}

