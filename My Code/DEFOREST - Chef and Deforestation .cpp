#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 250005;
struct Data{ int x,h,hx; }a[N];
struct Node{ ll sum; int cnt; }tree[4*N];
set<int>ss;
map<int,int>mp;
map<int,int>sp;
vector<int>vec;
vector<int>G[N];
vector<double>profit;

bool cmp(Data xx, Data yy){
    return xx.x < yy.x;
}

void CLEAR_ALL(int n){
    memset(tree,0,sizeof(tree));
    ss.clear();
    mp.clear();
    sp.clear();
    vec.clear();
    for(int i=0; i<=n; i++)G[i].clear();
}

double get_dist(double x,double h){
    return sqrt((x*x)+(h*h));
}

void update(int node,int b,int e,int x,int v){
    if(b==x && e==x){
        tree[node].sum += v;
        tree[node].cnt+=1;
        return;
    }
    int lson=(node<<1), rson=lson+1, m=(b+e)>>1;
    if(x<=m)update(lson,b,m,x,v);
    else update(rson,m+1,e,x,v);
    tree[node].sum = tree[lson].sum + tree[rson].sum;
    tree[node].cnt = tree[lson].cnt + tree[rson].cnt;
}

Node query(int node,int b,int e,int x,int y){
    if(b==x && e==y)return tree[node];
    int lson=(node<<1), rson=lson+1, m=(b+e)>>1;
    if(y<=m)return query(lson,b,m,x,y);
    else if(x>m)return query(rson,m+1,e,x,y);
    else{
        Node f1 = query(lson,b,m,x,m);
        Node f2 = query(rson,m+1,e,m+1,y);
        Node f;
        f.sum = f1.sum + f2.sum;
        f.cnt = f1.cnt + f2.cnt;
        return f;
    }
}

int main(){
    int tt; scanf("%d",&tt);
    while(tt--){
        int n; scanf("%d",&n);
        CLEAR_ALL(n);
        for(int i=1; i<=n; i++){
            scanf("%d%d",&a[i].x,&a[i].h);
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1; i<=n; i++){
            ss.insert(a[i].h - a[i].x);
            a[i].hx = a[i].h - a[i].x;
        }
        int k = 0;
        for(auto v : ss){
            mp[v] = ++k;
            sp[k] = v;
            vec.push_back(v);
        }
        for(int i=1; i<=n; i++){
            G[mp[a[i].hx]].push_back(i);
        }

        double ans = -1e+40;
        int flag = 0;
        for(int id=k; id>0; id--){
            int sz = (int)G[id].size();
            if(sz==0)continue;
            if(sz==1){
                int ii = G[id][0];
                update(1,1,n,ii,a[ii].hx);
                continue;
            }

            flag = 1;
            profit.clear();
            for(int i=0; i<sz-1; i++){
                int ii = G[id][i];
                int jj = G[id][i+1];
                Node val = query(1,1,n,ii,jj);
                double dist = get_dist(a[jj].x-a[ii].x+0.0, a[jj].h-a[ii].h+0.0);
                double prof = dist - (val.sum - (val.cnt*sp[id]));
                profit.push_back(prof);
            }

            /// 1D Maximum Subarray Sum[Kadane Algorithm]
            double have = 0.0;
            for(int i=0; i<profit.size(); i++){
                have += profit[i];
                ans = max(ans,have);
                have = max(have,0.0);
            }

            for(int i=0; i<sz; i++){
                int ii = G[id][i];
                update(1,1,n,ii,a[ii].hx);
            }
        }

        if(flag==0){
            printf("-1\n");
        }else{
            printf("%.9f\n",ans);
        }
    }
    return 0;
}
