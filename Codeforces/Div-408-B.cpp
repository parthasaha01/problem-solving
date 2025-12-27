#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
bool flag[mx+5];
struct dt{
    int u,v;
}st[300005];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    memset(flag,false,sizeof(flag));

    for(int i=1; i<=m; i++){
        int x; scanf("%d",&x);
        flag[x]=true;
    }

    for(int i=1; i<=k; i++)
    {
        scanf("%d%d",&st[i].u,&st[i].v);
    }

    if(flag[1]==true){
        printf("1\n");
        return 0;
    }

    int pr=1;

    for(int i=1; i<=k; i++)
    {
        int u,v;
        u = st[i].u;
        v = st[i].v;

        if(pr==u){
            pr=v;
            if(flag[pr]==true){
                break;
            }
        }
        else if(pr==v){
            pr=u;
            if(flag[pr]==true){
                break;
            }
        }
    }

    printf("%d\n",pr);

    return 0;
}
