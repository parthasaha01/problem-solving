#include<bits/stdc++.h>
using namespace std;
int n,l;
int ka[105],sb[105];
bool vis1[200],vis2[200];
bool check()
{
    for(int i=0; i<l; i++)
    {
        memset(vis1,false,sizeof(vis1));
        for(int k=1; k<=n; k++)
        {
            int ps = i-ka[k];
            if(ps<0)ps=ps+l;
            vis1[ps]=true;
        }
        for(int j=0; j<l; j++)
        {
            memset(vis2,false,sizeof(vis2));
            for(int k=1; k<=n; k++)
            {
                int ps = j-sb[k];
                if(ps<0)ps=ps+l;
                vis2[ps]=true;
            }
            int cnt=0;
            for(int p=0; p<l; p++){
                if(vis1[p]==true && vis2[p]==true)cnt++;
            }

            if(cnt==n)return true;
        }
    }

    return false;
}
int main()
{
    scanf("%d%d",&n,&l);

    for(int i=1; i<=n; i++)scanf("%d",&ka[i]);
    for(int i=1; i<=n; i++)scanf("%d",&sb[i]);

    if(check()==true)printf("YES");
    else printf("NO");

    return 0;
}
