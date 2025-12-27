#include<bits/stdc++.h>
using namespace std;
int cnt[105];
set<int>ss;
int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        int x; scanf("%d",&x);
        ss.insert(x);
        cnt[x]++;
    }

    int sz = ss.size();

    if(sz!=2){
        printf("NO\n");
        return 0;
    }

    int x=0,y=0,u=0,v=0;

    for(int i=1; i<=100; i++)
    {
        if(cnt[i]!=0){
            x = i;
            u=cnt[i];
            cnt[i]=0;
            break;
        }
    }

    for(int i=1; i<=100; i++)
    {
        if(cnt[i]!=0){
            y = i;
            v=cnt[i];
            cnt[i]=0;
            break;
        }
    }

    if(u==v)
    {
        printf("YES\n");
        printf("%d %d\n",x,y);
        return 0;
    }
    else{
        printf("NO\n");
    }

    return 0;
}
