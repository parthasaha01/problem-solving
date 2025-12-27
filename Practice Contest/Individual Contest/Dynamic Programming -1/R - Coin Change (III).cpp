#include<bits/stdc++.h>
using namespace std;
int coin[105],C[1005];
int way[100005],cnt[100005];
int main()
{
    int tt;scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,m;scanf("%d %d",&n,&m);

        for(int i=1;i<=n;i++) scanf("%d",&coin[i]);
        for(int i=1;i<=n;i++) scanf("%d",&C[i]);

        memset(way,0,sizeof(way));
        way[0]=1;

        for(int i=1; i<=n; i++)
        {
            memset(cnt,0,sizeof(cnt));

            for(int make=coin[i]; make<=m; make++)
            {
                int need = make-coin[i];
                if(way[make])continue;
                if(!way[need])continue;
                if(cnt[need]>=C[i])continue;

                way[make]=true;
                cnt[make]=cnt[need]+1;
            }
        }

        int ans=0;
        for(int i=1; i<=m; i++)if(way[i])ans++;

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}

