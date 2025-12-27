#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int a[1005][1005];
ll c[1005];
int main()
{
    int n=1000;
    int m;
    c[0]=0;
    c[1]=0;
    c[2]=1;
    for(int i=3; i<1005; i++){
        c[i]=c[i-1]+i-1;
    }

    while(scanf("%d",&m)==1)
    {
        memset(a,0,sizeof(a));

        for(int i=1; i<=m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            a[u][v]=1;
        }

        ll cnt;
        ll ans=0;

        cnt=0;
        for(int i=1; i<=n; i++){
            if(a[i][i]==1){
                cnt++;
            }
        }
        ans+=c[cnt];

        cnt=0;
        for(int i=1; i<=n; i++){
            if(a[i][n-i+1]==1){
                cnt++;
            }
        }
        ans+=c[cnt];

        for(int k=2; k<=n-1; k++)
        {
            int j=1;
            cnt=0;
            for(int i=k; i>=1; i--,j++)
            {
                if(a[i][j]==1){
                    ++cnt;
                }
            }
            ans+=c[cnt];
        }

        for(int k=2; k<=n-1; k++)
        {
            int i=n;
            cnt=0;
            for(int j=k; j<=n; j++,i--)
            {
                if(a[i][j]==1){
                    ++cnt;
                }
            }
            ans+=c[cnt];
        }

        for(int k=2; k<=n-1; k++)
        {
            int j=1;
            cnt=0;
            for(int i=k; i<=n; i++,j++)
            {
                if(a[i][j]==1){
                    ++cnt;
                }
            }
            ans+=c[cnt];
        }

        for(int k=2; k<=n-1; k++)
        {
            int i=1;
            cnt=0;
            for(int j=k; j<=n; j++,i++)
            {
                if(a[i][j]==1){
                    ++cnt;
                }
            }
            ans+=c[cnt];
        }

        printf("%I64d\n",ans);
    }

    return 0;
}
/*
25
1 1
1 2
1 3
1 4
1 5
2 1
2 2
2 3
2 4
2 5
3 1
3 2
3 3
3 4
3 5
4 1
4 2
4 3
4 4
4 5
5 1
5 2
5 3
5 4
5 5
*/
