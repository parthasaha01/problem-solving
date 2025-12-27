#include<bits/stdc++.h>
using namespace std;
#define mx 100205
#define ll long long
vector<int>pr;
int a[505][505],need[505][505],flag[mx+5],n,m;
void sieve()
{
    pr.push_back(2);
    for(ll i=3; i<=mx; i+=2){
        if(!flag[i]){
            pr.push_back(i);
            for(ll j=i*i; j<=mx; j+=2*i){
                flag[j]=true;
            }
        }
    }
}
int fun(int v)
{
    int lo=0;
    int hi=pr.size()-1;
    int x=0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;

        if(pr[md]==v){
            x = pr[md]; break;
        }
        else if(pr[md]<v) lo=md+1;
        else{
            x = pr[md];
            hi = md-1;
        }
    }

    return x-v;
}

bool check(int v)
{
    for(int i=1; i<=n; i++){
        int sum=0;
        for(int j=1; j<=m; j++){
            sum+=need[i][j];
        }
        if(sum<=v)return true;
    }

    for(int j=1; j<=m; j++){
        int sum=0;
        for(int i=1; i<=n; i++){
            sum+=need[i][j];
        }
        if(sum<=v)return true;
    }

    return false;
}
int main()
{
    sieve();

    scanf("%d%d",&n,&m);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int v = a[i][j];
            need[i][j] = fun(v);
        }
    }

//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=m; j++){
//            printf("%d ",need[i][j]);
//        }
//        printf("\n");
//    }

    int lo=0;
    int hi=1000000000;
    int ans;

    while(lo<=hi)
    {
        int md = (lo+hi)/2;

        if(check(md)){
            ans = md;
            hi=md-1;
        }
        else{
            lo=md+1;
        }
    }

    printf("%d\n",ans);

    return 0;
}
