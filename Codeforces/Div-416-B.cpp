#include<bits/stdc++.h>
using namespace std;
int pos[10005],qq[10004],a[10004];
int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        memset(pos,0,sizeof(pos));
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            pos[a[i]] = i;
        }

        for(int k=1; k<=m; k++)
        {
            int lf,rg,x;
            scanf("%d%d%d",&lf,&rg,&x);

            memset(qq,0,sizeof(qq));
            for(int i=lf; i<=rg; i++){
                qq[a[i]] = 1;
            }

            int cnt=lf-1;
            int v=0;
            int bg=1;
            while(cnt<x)
            {
                while(qq[bg]==0)
                {
                    bg++;
                }
                v=bg;
                cnt++;
                //printf("v=%d bg=%d cnt=%d\n",v,bg,cnt);
                bg++;
            }

            if(a[x]==v)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

