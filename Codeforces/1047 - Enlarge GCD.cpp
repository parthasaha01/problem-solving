#include<bits/stdc++.h>
using namespace std;
const int MAXN = 15000005;
int arr[MAXN], vis[MAXN], pr[MAXN];
void sieve(){
    for(int i=1; i<=MAXN; i++) vis[i]=i;
    for(int i=2; i<=MAXN; i++){
        if(vis[i]==i){
            for(int j=i; j<=MAXN; j+=i){
                vis[j] = min(vis[j],i);
            }
        }
    }
}
void fun(int v){
    while(v>1){
        pr[vis[v]]++;
        int f = vis[v];
        while(vis[v]==f){
            v /= vis[v];
        }
    }
}
int solve(int n){
    for(int i=0; i<n; i++){
        fun(arr[i]);
    }
    int maxx = 0;
    for(int i=2; i<=MAXN; i++){
        if(vis[i]==i){
            maxx = max(maxx, pr[i]);
        }
    }
    return n-maxx;
}
int main(){
    int n; scanf("%d",&n);
    int gcd = 0;
    for(int i =0 ; i < n; i++){
        scanf("%d",&arr[i]);
        gcd = __gcd(gcd,arr[i]);
    }

    for(int i = 0; i < n; i++) arr[i]/=gcd;

    int ck = 0;
    for(int i = 0; i <n; i++){
        if(arr[i]!=1){
            ck = 1;
            break;
        }
    }

    if(ck == 0){
        cout<<-1<<endl;
        return 0;
    }

    sieve();
    cout << solve(n) << endl;

    return 0;
}
