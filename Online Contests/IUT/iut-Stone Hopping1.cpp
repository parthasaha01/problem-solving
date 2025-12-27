#include<bits/stdc++.h>
using namespace std;
priority_queue<int>pq[301];
int n,m,s,cnt;
void fun(int x,int y){
    int flag=0;
    for(int u=x+1; u<=n; u++)
        if(pq[u].size()>=1){
            if(pq[u].top()>y){
                fun(u,pq[u].top());
                pq[u].pop(),flag=1;break;
            }
        }
    if(flag==0)cnt++;
}
int main(){
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        scanf("%d%d%d",&n,&m,&s);
        for(int i=1; i<=s; i++){
            int x,y; scanf("%d %d",&x,&y);
            pq[x].push(y);
        }
        cnt=0;
        for(int i=1; i<=n; i++)
            while(!pq[i].empty()){
                fun(i,pq[i].top());
                pq[i].pop();
            }
        printf("Case %d: %d\n",ks,cnt);
    }
}

