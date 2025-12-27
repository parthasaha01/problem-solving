#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int n,m,q,ans[mx],ar[1005][1005];
vector<int>typ[mx],qyr[mx],row[mx],col[mx];
void DFS(int u,int value)
{
    ans[u] = value;

    for(int i=0; i<qyr[u].size(); i++)
    {
        int v = qyr[u][i];
        int t = typ[u][i];

        if(t==1)
        {
            int temp = ar[row[u][i]][col[u][i]];
            ar[row[u][i]][col[u][i]] = 1;
            if(temp==0)value++;

            DFS(v,value);

            if(temp==0){
                ar[row[u][i]][col[u][i]] = 0;
                value--;
            }
        }
        else if(t==2)
        {
            int temp = ar[row[u][i]][col[u][i]];
            ar[row[u][i]][col[u][i]] = 0;
            if(temp==1)value--;

            DFS(v,value);

            if(temp==1){
                ar[row[u][i]][col[u][i]] = 1;
                value++;
            }
        }
        else if(t==3)
        {
            for(int j=1; j<=m; j++){
                if(ar[row[u][i]][j]==0){
                    ar[row[u][i]][j]=1;
                    value++;
                }
                else{
                    ar[row[u][i]][j]=0;
                    value--;
                }
            }

            DFS(v,value);

            for(int j=1; j<=m; j++){
                if(ar[row[u][i]][j]==0){
                    ar[row[u][i]][j]=1;
                    value++;
                }
                else{
                    ar[row[u][i]][j]=0;
                    value--;
                }
            }
        }
        else if(t==4)
        {
            DFS(v,value);
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);

    for(int i=1; i<=q; i++)
    {
        int t; scanf("%d",&t);

        if(t==1)
        {
            int r,c; scanf("%d%d",&r,&c);
            typ[i-1].push_back(t);
            qyr[i-1].push_back(i);
            row[i-1].push_back(r);
            col[i-1].push_back(c);
        }
        else if(t==2)
        {
            int r,c; scanf("%d%d",&r,&c);
            typ[i-1].push_back(t);
            qyr[i-1].push_back(i);
            row[i-1].push_back(r);
            col[i-1].push_back(c);
        }
        else if(t==3)
        {
            int r; scanf("%d",&r);
            typ[i-1].push_back(t);
            qyr[i-1].push_back(i);
            row[i-1].push_back(r);
        }
        else if(t==4)
        {
            int k; scanf("%d",&k);
            typ[k].push_back(t);
            qyr[k].push_back(i);
        }
    }

    DFS(0,0);

    for(int i=1; i<=q; i++)printf("%d\n",ans[i]);

    return 0;
}
