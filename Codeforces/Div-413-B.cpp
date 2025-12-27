#include<bits/stdc++.h>
using namespace std;
#define mx 200005
map<int,bool>mp;
int st[mx],ans[mx];
vector<int>vv[4];
int s[mx];
int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&st[i]);
        mp[st[i]]=true;
    }
    for(int i=1; i<=n; i++)
    {
        int x; scanf("%d",&x);
        vv[x].push_back(st[i]);
    }
    for(int i=1; i<=n; i++)
    {
        int x; scanf("%d",&x);
        vv[x].push_back(st[i]);
    }

    if(vv[1].size()!=0) sort(vv[1].begin(),vv[1].end());
    if(vv[2].size()!=0) sort(vv[2].begin(),vv[2].end());
    if(vv[3].size()!=0) sort(vv[3].begin(),vv[3].end());

    int m;
    scanf("%d",&m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d",&s[i]);
    }

    int c1=-1,c2=-1,c3=-1;
    for(int i=1; i<=m; i++)
    {
        int pp = s[i];

        if(pp==1)
        {
            ans[i]=-1;
            c1++;
            while(c1<vv[1].size())
            {
                int x = vv[1][c1];
                if(mp[x]==true){
                    ans[i]=x;
                    mp[x]=false;
                    break;
                }
                c1++;
            }
        }
        else if(pp==2)
        {
            ans[i]=-1;
            c2++;
            while(c2<vv[2].size())
            {
                int x = vv[2][c2];
                if(mp[x]==true){
                    ans[i]=x;
                    mp[x]=false;
                    break;
                }
                c2++;
            }
        }
        else
        {
            ans[i]=-1;
            c3++;
            while(c3<vv[3].size())
            {
                int x = vv[3][c3];
                if(mp[x]==true){
                    ans[i]=x;
                    mp[x]=false;
                    break;
                }
                c3++;
            }
        }
    }

    for(int i=1; i<=m; i++)
    {
        if(i==m)printf("%d\n",ans[i]);
        else printf("%d ",ans[i]);
    }

    return 0;
}
