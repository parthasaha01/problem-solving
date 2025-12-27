#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
int coin[101],C[1001],cnt[100001];
bool way[100001];
int main()
{
    int T;
    scanf("%d",&T);

    for(int ks=1; ks<=T; ks++)
    {
        int n,m;
        scanf("%d %d",&n,&m);

        for(int i=0;i<n;i++)
            scanf("%d",&coin[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&C[i]);

        memset(way,false,sizeof(way));

        way[0]=1;
        int ans=0;;

        for(int i=0; i<n; i++)
        {
            memset(cnt,0,sizeof(cnt));

            for(int make=coin[i]; make<=m; make++)
            {
                if(!way[make] && way[make-coin[i]]!=0 && cnt[make-coin[i]]<C[i])
                {
                    way[make]=true;
                    cnt[make]=cnt[make-coin[i]]+1;
                    ans++;
                }
            }
        }

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
