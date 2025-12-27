#include<bits/stdc++.h>
using namespace std;
priority_queue<int>pq[305];
int n,m,s,cnt;
void fun(int x,int y)
{
    int flag=0;

    for(int u=x+1; u<=n; u++)
    {
        if(pq[u].size()>=1)
        {
            int v = pq[u].top();
            if(v>y){
                pq[u].pop();
                flag=1;
                fun(u,v);
                break;
            }
        }
    }

    if(flag==0)cnt++;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d%d",&n,&m,&s);

        for(int i=1; i<=s; i++)
        {
            int x,y; scanf("%d %d",&x,&y);
            pq[x].push(y);
        }

        cnt=0;

        for(int i=1; i<=n; i++)
        {
            while(!pq[i].empty())
            {
                int x=i;
                int y=pq[i].top();
                pq[i].pop();
                fun(x,y);
            }
        }

        printf("Case %d: %d\n",ks,cnt);

    }

    return 0;
}
