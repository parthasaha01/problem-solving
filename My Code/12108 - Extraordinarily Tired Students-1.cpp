#include<bits/stdc++.h>
using namespace std;
struct dt{
    int a,b,c;
}st[15];
int n;
int state[15];
queue<int>Q[15];

int check(int t)
{
    int cnt = 0;
   // printf("t=%d:\n",t);
    for(int i=1; i<=n; i++){
        int x = Q[i].front();
        if(x==0)cnt++;
        //printf("%d %d\n",x,Q[i].size());
    }
    //printf("cnt=%d\n",cnt);


    if(cnt==n)return 1;

    for(int i=1; i<=n; i++)
    {
        int x = Q[i].front();

        if(x==1 && Q[i].size()==1)
        {
            //printf("i=%d x=%d t=%d\n",i,x,t);
            while(!Q[i].empty()) Q[i].pop();
            for(int j=1; j<=st[i].a; j++)Q[i].push(0);
            for(int j=1; j<=st[i].b; j++)Q[i].push(1);
        }
        else if(x==0 && Q[i].size()==st[i].b+1 && n <= cnt*2)
        {
            //printf("i=%d x=%d t=%d\n",i,x,t);
            while(!Q[i].empty()) Q[i].pop();
            for(int j=1; j<=st[i].a; j++)Q[i].push(0);
            for(int j=1; j<=st[i].b; j++)Q[i].push(1);
        }
        else
        {
            Q[i].pop();
        }
    }
    //printf("\n");
    //getchar();

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

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=st[i].a; j++)Q[i].push(0);
            for(int j=1; j<=st[i].b; j++)Q[i].push(1);
            for(int j=1; j<st[i].c; j++)Q[i].pop();
        }

        int ans = -1;
        for(int t=1; t<=100000; t++)
        {
            int f = check(t);
            if(f){
                ans = t;
                break;
            }
        }

        printf("Case %d: %d\n",++ks,ans);

        for(int i=1; i<=n; i++){
            while(!Q[i].empty()){
                Q[i].pop();
            }
        }
    }
    return 0;
}
