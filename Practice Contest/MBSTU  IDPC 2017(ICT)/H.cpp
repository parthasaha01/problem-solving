#include<bits/stdc++.h>
using namespace std;
#define maxx 100015
int st[maxx][20];
int s[maxx];
void create_sptable(int N)
{
    for(int i=0; i<N; i++) st[i][0]=i;

    for(int k=1; (1<<k)<N; k++)
    {
        for(int i=0; i+(1<<k)-1<N; i++)
        {
            int x = st[i][k-1];
            int y = st[i+(1<<(k-1))][k-1];

            if(s[x]<=s[y]) st[i][k]=x;
            else st[i][k]=y;
        }
    }
}
int RMQ(int b,int e)
{
    int x,y,k;

    if(e-b>1){
        k = (int)log2(e-b+1);
        x = st[b][k];
        y = st[e-(1<<k)+1][k];
    }
    else{
        x=b;
        y=e;
    }

    return min(s[x],s[y]);
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,k; scanf("%d%d",&n,&k);

        for(int i=0; i<n; i++)scanf("%d",&s[i]);

        create_sptable(n);

        printf("Case %d:\n",ks);
        for(int i=1; i<=k; i++)
        {
            int x,y; scanf("%d%d",&x,&y);
            x--, y--;
            if(x>y)swap(x,y);
            int ans = RMQ(x,y);
            printf("%d\n",ans);
        }
    }

    return 0;
}

