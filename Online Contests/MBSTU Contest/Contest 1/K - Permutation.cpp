#include<bits/stdc++.h>
using namespace std;
int a[5005];
bool vis[5005];
int main()
{
    int n,cnt,res;

    while(cin >> n)
    {
        memset(vis,false,sizeof(vis));
        cnt=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);

            if(vis[a[i]]==false && a[i]<=n)
            {
                ++cnt;
                vis[a[i]]=true;
            }
        }

        res=n-cnt;

        cout << res << endl;
    }

    return 0;
}
