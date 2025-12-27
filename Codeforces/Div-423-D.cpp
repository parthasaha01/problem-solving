#include<bits/stdc++.h>
using namespace std;
int n,k,aa[200005];
struct dt
{
    int u,v;
}st[200005];
int main()
{
    while(scanf("%d%d",&n,&k)==2)
    {
        int p=0;
        int v=1;
        int x=0;
        int lv=1;
        for(int i=1; i<=k; i++)
        {
            ++p;
            v++;
            x++;

            st[p].u=1;
            st[p].v=v;
            aa[x]=v;
        }
        x=1;
        if(p<n-1)lv++;
        while(p<n-1)
        {
            if(x>k)
            {
                x=1;
                lv++;
            }

            ++p;
            v++;
            st[p].u=aa[x];
            st[p].v=v;
            aa[x]=v;
            x++;
        }

        int rr = (n-1)%k;

        int ans = (2*lv);
        if(rr==1)ans--;

        printf("%d\n",ans);
        for(int i=1; i<=p; i++)
        {
            printf("%d %d\n",st[i].u, st[i].v);
        }
    }
    return 0;
}
