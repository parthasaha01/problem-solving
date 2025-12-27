#include <bits/stdc++.h>
using namespace std;
struct dt{
    int a,b,c,s;
}st[15];
int n;

int check()
{
    int cnt = 0;
    for (int i=1; i<=n; i++){
        int a,b,c,s;
        a = st[i].a; b = st[i].b;
        c = st[i].c; s = st[i].s;
        if(s<=a) cnt++;
    }

    if(cnt==n) return 1;

    for(int i=1; i<=n; i++){
        int a,b,c,s;
        a = st[i].a; b = st[i].b;
        c = st[i].c; s = st[i].s;

        if(s==a+b) st[i].s=1;
        else if(s==a && n<=cnt*2) st[i].s=1;
        else st[i].s++;
    }

    return 0;
}
int main()
{
    int ks=0;
    while(scanf("%d",&n) && n)
    {
        for(int i=1; i<=n; i++){
            scanf("%d%d%d",&st[i].a,&st[i].b,&st[i].c);
        }

        for(int i=1; i<=n; i++){
            st[i].s = st[i].c;
        }

        int ans = -1;
        for(int t=1; t<=100000; t++)
        {
            if(check()){
                ans = t;
                break;
            }
        }
        printf("Case %d: %d\n",++ks,ans);
    }
    return 0;
}