#include<bits/stdc++.h>
using namespace std;
#define MAXN 300000
int f[MAXN+5],d[MAXN+5],q[MAXN+5],qn,ans;
int main()
{
    int n,m,t,x,i=0;
    scanf("%d%d",&n,&q);

    while(m--)
    {
        scanf("%d%d",&t,&x);

        if(t==1)
        {
            f[x]++;
            ans++;
            q[qn]=x;
            qn++;   //qn=total
        }
        if(t==2)
        {
            ans-=f[x];
            f[x]=0;
            d[x]=qn;
        }
        if(t==3)
        {
            for(; i<x; i++)
            {
                if(i>=d[q[i]])
                {
                    f[q[i]]--;
                    ans--;
                }
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
