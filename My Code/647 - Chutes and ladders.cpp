#include<bits/stdc++.h>
using namespace std;
map<int,int>mp,tp;
int s[105],v[10];
bool flag[105];
int main()
{
    int k=0,x;
    while(scanf("%d",&x) && x)
    {
        s[++k] = x;
    }

    int n;
    while(scanf("%d",&n) && n)
    {
        mp.clear();
        for(int i=0; i<=100; i++)mp[i]=i;

        int lb,ub;
        while(scanf("%d%d",&lb,&ub))
        {
            if(lb==0&&ub==0)break;
            mp[lb]=ub;
            //if(lb<ub)mp[lb]=ub;
            //else mp[lb]=ub;
        }

        tp.clear();
        while(scanf("%d",&x) && x)
        {
            if(x<0){
               x = -x;
                tp[x]=1;
            }
            else tp[x]=2;
        }

        memset(v,0,sizeof(v));
        memset(flag,true,sizeof(flag));
        int p=1,winner=0;
        for(int i=1; i<=k; i++)
        {
            while(1)
            {
                if(flag[p]==false)
                {
                    flag[p]=true;
                    p++;
                    if(p>n)p=1;
                }
                else{
                    break;
                }
            }

            //printf("v[1]=%d v[2]=%d flag[1]=%d flag[2]=%d p=%d s[%d]=%d\n",v[1],v[2],flag[1],flag[2],p,i,s[i]);

            if(v[p]+s[i]>100){
                p++; continue;
            }

            if(v[p]+s[i]==100){
                winner = p; break;
            }

            v[p] += s[i];
            v[p] = mp[v[p]];

            if(tp[v[p]]==1){
                flag[p]=false;
                p++;
                if(p>n)p=1;
            }
            else if(tp[v[p]]!=2){
                p++;
                if(p>n)p=1;
            }

            //printf("v[1]=%d v[2]=%d flag[1]=%d flag[2]=%d p=%d s[%d]=%d\n\n",v[1],v[2],flag[1],flag[2],p,i,s[i]);
        }

        printf("%d\n",winner);
    }
    return 0;
}
/*
3 6 3 2 5 1 3 4 2 3 1 2 0
2
6 95
99 1
0 0
-3
98
0
2
3 99
6 90
0 0
0
0
*/
