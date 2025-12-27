#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int a[mx+5],b[mx+5],flag[mx+5];
vector<int>vv;
int cnt[mx+5];
int main()
{
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        b[i]=a[i];
    }

    for(int i=1; i<=n; i++)
    {
        if(cnt[i]==0)
        {
            vv.push_back(i);
        }
    }

    int k=0;
    for(int i=1; i<=n; i++)
    {
        if(cnt[a[i]]>1)
        {
            if(vv[k]<a[i] || flag[a[i]]==1)
            {
                cnt[a[i]]--;
                b[i]=vv[k];
                flag[b[i]]=1;
                k++;
            }
            else
            {
                cnt[a[i]]--;
                flag[a[i]]=1;
            }
        }
        else if(cnt[a[i]]==1 && flag[a[i]]==1)
        {
            b[i]=vv[k];
            flag[b[i]]=1;
            k++;
        }
        else{
            b[i]=a[i];
            flag[a[i]]=1;
        }
    }

    int sz = vv.size();
    printf("%d\n",sz);

    for(int i=1; i<=n; i++)
    {
        if(i==n)printf("%d\n",b[i]);
        else printf("%d ",b[i]);
    }

    return 0;
}
