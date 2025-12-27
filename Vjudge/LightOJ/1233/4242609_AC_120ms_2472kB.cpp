#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
int n,m;
int coin[101],C[1001];
int way[100001],cnt[100001];
int main()
{
    int T;
    scanf("%d",&T);

    for(int test=1; test<=T; test++)
    {
        scanf("%d %d",&n,&m);

        for(int i=0;i<n;i++)
            scanf("%d",&coin[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&C[i]);

        memset(way,0,sizeof(way));

        way[0]=1;
        long int Max=0,Mx=0,res=0;;

        for(int i=0; i<n; i++)
        {
            memset(cnt,0,sizeof(cnt));

            for(int make=coin[i]; make<=m; make++)
            {
                if(!way[make] && way[make-coin[i]]!=0)
                {
                    if(cnt[make-coin[i]]<C[i])
                    {
                        way[make]=1;
                        cnt[make]=cnt[make-coin[i]]+1;
                        res++;
                    }

                }
            }
        }


        printf("Case %d: %ld\n",test,res);
    }

    return 0;
}
