#include<bits/stdc++.h>
using namespace std;
int v[1001][1001],p[1001][1001];
int rowtree[1001][4001],coltree[1001][4001];
void rowUpdate(int id,int nd,int b,int e,int x,int val)
{
    if(b==x&&e==x){
        rowtree[id][nd] = val;
        return;
    }
    int lf=2*nd, rg = 2*nd+1, md = (b+e)/2;
    if(x<=md)rowUpdate(id,lf,b,md,x,val);
    else rowUpdate(id,rg,md+1,e,x,val);
    rowtree[id][nd] = max(rowtree[id][lf],rowtree[id][rg]);
}
void colUpdate(int id,int nd,int b,int e,int x,int val)
{
    if(b==x&&e==x){
        coltree[id][nd] = val;
        return;
    }
    int lf=2*nd, rg = 2*nd+1, md = (b+e)/2;
    if(x<=md)colUpdate(id,lf,b,md,x,val);
    else colUpdate(id,rg,md+1,e,x,val);
    coltree[id][nd] = max(coltree[id][lf],coltree[id][rg]);
}
int rowQuery(int id,int nd,int b,int e,int x,int y)
{
    if(b>y||e<x)return -1000000000;
    if(b>=x&&e<=y)return rowtree[id][nd];
    int lf=2*nd, rg = 2*nd+1, md = (b+e)/2;
    int m1 = rowQuery(id,lf,b,md,x,y);
    int m2 = rowQuery(id,rg,md+1,e,x,y);
    return max(m1,m2);
}
int colQuery(int id,int nd,int b,int e,int x,int y)
{
    if(b>y||e<x)return -1000000000;
    if(b>=x&&e<=y)return coltree[id][nd];
    int lf=2*nd, rg = 2*nd+1, md = (b+e)/2;
    int m1 = colQuery(id,lf,b,md,x,y);
    int m2 = colQuery(id,rg,md+1,e,x,y);
    return max(m1,m2);
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,m; scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                scanf("%d",&p[i][j]);
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                scanf("%d",&v[i][j]);
            }
        }

        for(int i=1; i<=1000; i++){
            for(int j=1; j<=4000; j++){
                rowtree[i][j] = -1000000000;
                coltree[i][j] = -1000000000;
            }
        }

        rowUpdate(n,1,1,m,m,v[n][m]);
        colUpdate(m,1,1,n,n,v[n][m]);
        //a[n][m] = v[n][m];

        for(int j=m; j>=1; j--)
        {
            for(int i=n; i>=1; i--)
            {
                if(i==n&&j==m)continue;
                int rowcnt=-1000000000;
                int colcnt=-1000000000;
                if(j<m)
                {
                    int x = j+1;
                    int y = min(j+p[i][j],m);
                    rowcnt = rowQuery(i,1,1,m,x,y);
                    //printf("i=%d j=%d x=%d y=%d rowcnt=%d\n",i,j,x,y,rowcnt);
                }
                if(i<n)
                {
                    int x = i+1;
                    int y = min(i+p[i][j],n);
                    colcnt = colQuery(j,1,1,n,x,y);
                   // printf("i=%d j=%d x=%d y=%d colcnt=%d\n",i,j,x,y,colcnt);
                }

                int maxx = max(rowcnt,colcnt);
                //a[i][j] = maxx+v[i][j];
                //printf("a[%d][%d]=%d\n\n",i,j,a[i][j]);
                //getchar();
                rowUpdate(i,1,1,m,j,maxx+v[i][j]);
                colUpdate(j,1,1,n,i,maxx+v[i][j]);
            }
        }

        int ans = rowQuery(1,1,1,m,1,1);
        //int ans = a[1][1];
        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}
