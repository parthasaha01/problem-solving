#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int a[mx+5],ar[mx+5];
vector<int> tree[4*mx+5];
void MergeNode(int nd,int lf,int rg)
{
    int n1 = tree[lf].size();
    int n2 = tree[rg].size();
    int i=0,j=0;

    while(i<n1 && j<n2)
    {
        if(tree[lf][i]<=tree[rg][j]){
            tree[nd].push_back(tree[lf][i]);
            i++;
        }
        else{
            tree[nd].push_back(tree[rg][j]);
            j++;
        }
    }

    while(i<n1)
    {
        tree[nd].push_back(tree[lf][i]);
        i++;
    }
    while(j<n2)
    {
        tree[nd].push_back(tree[rg][j]);
        j++;
    }
}
void init(int nd,int b,int e)
{
    if(b==e){ tree[nd].push_back(a[b]); return; }
    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;
    init(lf,b,md);
    init(rg,md+1,e);
    MergeNode(nd,lf,rg);
}
int LowerBound(int nd,int v)
{
    int lo=0;
    int hi=tree[nd].size()-1;
    int cnt=0;

    while(lo<=hi)
    {
        int md=(lo+hi)/2;
        int u = tree[nd][md];
        if(u<v){
            cnt=md+1;
            lo = md+1;
        }
        else{
            hi=md-1;
        }
    }
    return cnt;
}
int query(int nd,int b,int e,int x,int y,int v)
{
    if(b>y||e<x)return 0;
    if(b>=x&&e<=y){
        int cnt = LowerBound(nd,v);
        return cnt;
    }
    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;
    int p1 = query(lf,b,md,x,y,v);
    int p2 = query(rg,md+1,e,x,y,v);
    return p1+p2;
}
int solve(int n,int x,int y,int k)
{
    int lo=1;
    int hi=n;
    int ans = -1;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        int v  = ar[md];

        int res = query(1,1,n,x,y,v);

        //printf("md=%d v=%d res=%d\n",md,ar[md],res);

        if(res<k){
            ans = v;
            lo = md+1;
        }
        else{
            hi = md-1;
        }
    }
    return ans;
}
int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)==2)
    {
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            ar[i] = a[i];
        }

        init(1,1,n);

//        for(int i=1; i<=15; i++){
//            printf("node %d: ",i);
//            for(int j=0; j<tree[i].size(); j++){
//                printf("%d ",tree[i][j]);
//            }
//            printf("\n");
//        }

        sort(ar+1,ar+n+1);

        for(int qq=1; qq<=q; qq++)
        {
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            int ans = solve(n,x,y,k);
            printf("%d\n",ans);
        }

        for(int i=0; i<4*mx; i++)tree[i].clear();
    }

    return 0;
}

/*
8 4
5 3 1 7 4 8 2 6
1 2 1
2 7 2
2 7 6
2 7 5

10 20
5 3 1 3 3 3 7 2 9 4
*/
