#include<bits/stdc++.h>
using namespace std;
int b[50005];
struct dt{
    int x,y;
    bool operator < (const dt &s)const{
        return s.y<y;
    }
}a[50005];
bool cmp(dt p,dt q)
{
    if(p.x==q.x) return p.y<q.y;
    else return p.x<q.x;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);

        for(int i=0; i<n; i++){
            scanf("%d%d",&a[i].x,&a[i].y);
        }

        sort(a,a+n,cmp);

        priority_queue<dt>pq;
        for(int i=0; i<n; i++)
        {
            int u=a[i].x;
            int v=a[i].y;
            pq.push(a[i]);
            dt top=pq.top();
            if(top.y<u){
                pq.pop();
            }
        }

        int ans=pq.size();
        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
/*
10

8
2 5
1 5
6 10
12 16
10 12
7 9
4 5
7 12

5
1 4
5 8
9 10
2 11
6 7

3
60 77
48 74
16 94

6
44 85
41 53
23 93
77 81
48 49
34 71

6
35 45
82 87
24 96
93 96
59 69
23 92

*/
