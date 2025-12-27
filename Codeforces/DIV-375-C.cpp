#include<bits/stdc++.h>
using namespace std;
int a[2005],cnt[2005],b[2005];
vector<int>kom,besi;
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }

        memset(cnt,0,sizeof(cnt));

        for(int i=0; i<n; i++)
        {
            if(a[i]<=m)
            {
                cnt[a[i]]++;
            }
        }

        int each=(n/m);

        kom.clear();

        for(int i=1; i<=m; i++)
        {
            if(cnt[i]<each)
            {
                for(int j=0; j<abs(each-cnt[i]); j++)
                {
                    kom.push_back(i);
                }
            }
        }

        int kdx=0;

        for(int i=0; i<n; i++)
        {
            int v=a[i];
            if(v<=m)
            {
                if(cnt[v]>each)
                {
                    if(kdx==kom.size()){
                        break;
                    }
                    int u=kom[kdx];
                    cnt[u]++;
                    cnt[v]--;
                    a[i]=u;
                    kdx++;
                }
            }
        }

        kom.clear();
        for(int i=1; i<=m; i++)
        {
            if(cnt[i]<each)
            {
                for(int j=0; j<abs(each-cnt[i]); j++)
                {
                    kom.push_back(i);
                }
            }
        }

        kdx=0;
        for(int i=0; i<n; i++)
        {
            if(kdx==kom.size()){
                break;
            }
            int v=a[i];
            if(v>m)
            {
                int u=kom[kdx];
                a[i]=u;
                kdx++;
            }
        }

        int minn=n/m;
        int change=0;
        for(int i=0; i<n; i++)
        {
            if(a[i]!=b[i])
            {
                change++;
            }
        }

        printf("%d %d\n",minn,change);
        for(int i=0; i<n-1; i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d\n",a[n-1]);
    }

    return 0;
}
/*
10 4
1 1 2 2 3 3 4 4 4 4
20 3
3 2 2 3 3 3 2 3 3 3 2 748578511 149249674 844954396 321901094 3 255089924 244803836 3 943090472
*/
