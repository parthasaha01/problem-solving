#include<bits/stdc++.h>
using namespace std;
int b[1005],vis[1005];
int solve(int n)
{
    stack<int>s;
    stack<int>a;

    for(int i=n; i>=1; i--)a.push(i);
    memset(vis,0,sizeof(vis));

    for(int i=1; i<=n; i++)
    {
        int x = b[i];

        if(vis[x]==0)
        {
            while(a.top()!=x)
            {
                vis[a.top()]=1;
                s.push(a.top());
                a.pop();
            }
            vis[a.top()] = 2;
            a.pop();
        }
        else
        {
            if(s.top()!=x)return 0;
            vis[s.top()]=2;
            s.pop();
        }
    }
    return 1;
}
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)break;

        while(scanf("%d",&b[1])){
            if(b[1]==0){
                printf("\n");
                break;
            }

            for(int i=2; i<=n; i++)scanf("%d",&b[i]);

            int ans = solve(n);

            if(ans==1)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}