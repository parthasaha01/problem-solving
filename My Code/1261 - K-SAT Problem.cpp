#include<bits/stdc++.h>
using namespace std;
vector<int>st[35];
bool vis[35];
void reset()
{
    memset(vis,false,sizeof(vis));
    for(int i=0; i<35; i++){
        st[i].clear();
    }
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        reset();

        int n,m,k;
        cin >> n >> m >> k;

        for(int i=1; i<=n; i++){
            for(int j=0; j<k; j++){
                int v;
                cin >> v;
                st[i].push_back(v);
            }
        }

        int p;
        scanf("%d",&p);
        for(int i=1; i<=p; i++){
            int x;
            cin >> x;
            vis[x]=true;
        }

        bool flag=true;
        for(int i=1; i<=n; i++){
            bool status=false;
            for(int j=0; j<k; j++){
                int v=st[i][j];
                if(v>0){
                    if(vis[v]==true){
                        status=true;
                        break;
                    }
                }
                else{
                    if(vis[-v]==false){
                        status=true;
                        break;
                    }
                }
            }
            if(status==false){
                flag=false;
                break;
            }
        }

        if(flag)
            printf("Case %d: Yes\n",ks);
        else
            printf("Case %d: No\n",ks);
    }

    return 0;
}
