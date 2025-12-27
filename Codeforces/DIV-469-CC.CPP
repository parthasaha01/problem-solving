#include<bits/stdc++.h>
using namespace std;
#define mx 200005
char s[200005];
int a[200005],n,p;
int one[4*mx], zero[4*mx];
set<int>ss;
vector<int>vv[mx];
void updateZero(int nd,int b,int e,int x,int v)
{
    if(b==x&&e==x){
        zero[nd] = v;
        return;
    }

    int lf=nd*2; int rg=lf+1; int md=(b+e)/2;

    if(x<=md)updateZero(lf,b,md,x,v);
    else updateZero(rg,md+1,e,x,v);
    zero[nd] = zero[lf]+zero[rg];
}
void updateOne(int nd,int b,int e,int x,int v)
{
    if(b==x&&e==x){
        one[nd] = v;
        return;
    }

    int lf=nd*2; int rg=lf+1; int md=(b+e)/2;

    if(x<=md)updateOne(lf,b,md,x,v);
    else updateOne(rg,md+1,e,x,v);
    one[nd] = one[lf]+one[rg];
}
int sumZero(int nd,int b,int e,int x,int y)
{
    if(b>y||e<x)return 0;
    if(b>=x&&e<=y)return zero[nd];
    int lf=nd*2; int rg=lf+1; int md=(b+e)/2;
    return sumZero(lf,b,md,x,y) + sumZero(rg,md+1,e,x,y);
}
int sumOne(int nd,int b,int e,int x,int y)
{
    if(b>y||e<x)return 0;
    if(b>=x&&e<=y)return one[nd];
    int lf=nd*2; int rg=lf+1; int md=(b+e)/2;
    return sumOne(lf,b,md,x,y) + sumOne(rg,md+1,e,x,y);
}
int queryZero(int nd,int b,int e,int v)
{
    if(b==e){
        if(zero[nd]==1)return b;
        else return 0;
    }
    int lf=nd*2; int rg=lf+1; int md=(b+e)/2;

    if(v<=zero[lf])return queryZero(lf,b,md,v);
    else return queryZero(rg,md+1,e,v-zero[lf]);
}
int queryOne(int nd,int b,int e,int v)
{
    if(b==e){
        if(one[nd]==1)return b;
        else return 0;
    }
    int lf=nd*2; int rg=lf+1; int md=(b+e)/2;

    if(v<=one[lf])return queryOne(lf,b,md,v);
    else return queryOne(rg,md+1,e,v-one[lf]);
}
int main()
{
    scanf("%s",&s);
    n = strlen(s);
    for(int i=0; i<n; i++){
        a[i+1] = s[i]-'0';
    }

    if(a[n]==1){
        printf("-1\n");
        return 0;
    }

    memset(one,0,sizeof(one));
    memset(zero,0,sizeof(zero));

    for(int i=1; i<=n; i++){
        if(a[i]==0) updateZero(1,1,n,i,1);
        else updateOne(1,1,n,i,1);
    }

    bool flag = true;

    for(int i=1; i<=n; i++) ss.insert(i);

    set<int> :: iterator it;
    int k = 0;

    for(k=1; k<=n && ss.size()>0; k++)
    {
        it = ss.begin();
        if(a[*it]==1){
            printf("-1\n");
            return 0;
        }

        int u,v,w;
        u = queryZero(1,1,n,1);
        updateZero(1,1,n,u,0);
        vv[k].push_back(u);
        ss.erase(u);

        while(u<n && ss.size()>1)
        {
            int on = 0;
            on = sumOne(1,1,n,1,u);
            v = queryOne(1,1,n,on+1);
            if(v<=u) break;

            int zr = 0;
            zr = sumZero(1,1,n,1,v);
            w = queryZero(1,1,n,zr+1);
            if(w<=v) break;

            vv[k].push_back(v);
            vv[k].push_back(w);
            updateOne(1,1,n,v,0);
            updateZero(1,1,n,w,0);
            ss.erase(v);
            ss.erase(w);
            u = w;
        }
    }

    if(vv[k].size()==0)k--;

    printf("%d\n",k);
    for(int i=1; i<=k; i++)
    {
        int sz = vv[i].size();
        printf("%d",sz);
        for(int j=0; j<sz; j++){
            printf(" %d",vv[i][j]);
        }
        printf("\n");
    }

    return 0;
}

