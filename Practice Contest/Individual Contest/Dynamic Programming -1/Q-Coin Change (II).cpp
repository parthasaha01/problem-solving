#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
int n,k;
int coin[101];
int way[10001];
int main()
{
    int T;
    scanf("%d",&T);

    for(int test=1; test<=T; test++)
    {
        scanf("%d %d",&n,&k);

        for(int i=0;i<n;i++)
            scanf("%d",&coin[i]);

        memset(way,0,sizeof(way));
        way[0]=1;

        for(int i=0; i<n; i++){
            for(int make=coin[i]; make<=k; make++){
                way[make]=(way[make]+way[make-coin[i]])%mod;
            }
        }

        printf("Case %d: %d\n",test,way[k]);
    }

    return 0;
}
