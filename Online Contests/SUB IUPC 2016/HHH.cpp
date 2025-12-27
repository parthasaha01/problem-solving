#include<bits/stdc++.h>
using namespace std;
bool flag[1005][1005];
int main()
{
    int n,m; scanf("%d%d",&n,&m);

    for(int i=1; i<=m; i++){
        int u,v; scanf("%d%d",&u,&v);
        if(flag[u][v]){
            printf("old\n");
        }
        else{
            printf("new\n");
            flag[u][v]=true;
            flag[v][u]=true;
        }

    }

    return 0;
}
