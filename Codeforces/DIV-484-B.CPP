#include<bits/stdc++.h>
using namespace std;
#define mx 400005
int n,a[mx],ans[mx];
string s;
struct dt{
    int id,w;
}st[mx];
bool cmp(dt p,dt q){
    return p.w < q.w;
}
struct dd
{
    int id,w;
    st(int idx, int ww)
    {
        id=idx;
        w=ww;
    }
    bool operator <(const dd& p)const{
        return w < p.w;
    }
};
priority_queue<dd>pq;
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        st[i].id = i;
        st[i].w = a[i];
    }

    sort(st+1,st+n+1,cmp);

    cin>>s;
    int cur = 1;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='0'){
            ans[i+1] = st[cur].id;
            dd tp;
            tp.id = st[cur].id;
            tp.w = st[cur].w;
            pq.push(tp);
            cur++;
        }
        else{
            dd tp = pq.top();
            pq.pop();
            ans[i+1] = tp.id;
        }
    }

    int nn = 2*n;
    for(int i=1; i<=nn; i++){
        if(i==nn)printf("%d\n",ans[i]);
        else printf("%d ",ans[i]);
    }

    return 0;
}
