#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100005
ll minv[mx],ua[mx],va[mx],la[mx],ka[mx];
bool vis[mx];
ll n,m,k;
int main()
{
    while(scanf("%I64d%I64d%I64d",&n,&m,&k)==3)
    {
        for(int i=0; i<=n; i++)
        {
            //minv[i]=9999999999999;
            vis[i]=false;
        }

        for(int i=0; i<m; i++)
        {
            scanf("%I64d%I64d%I64d",&ua[i],&va[i],&la[i]);

        }

        for(int i=0; i<k; i++){
            scanf("%I64d",&ka[i]);
            vis[ka[i]]=true;
        }

        ll minn=99999999999;
        bool flag=false;

        for(int i=0; i<m; i++)
        {
            ll u,v,l;
            u=ua[i];
            v=va[i];
            l=la[i];

            if(vis[u]==true && vis[v]==false)
            {
                if(l<minn){
                    minn=l;
                    flag=true;
                }
            }
            if(vis[v]==true && vis[u]==false)
            {
                if(l<minn){
                    minn=l;
                    flag=true;
                }
            }
        }


        if(flag==true){
            printf("%I64d\n",minn);
        }
        else{
            printf("-1\n");
        }
    }

    return 0;
}
