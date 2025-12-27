#include<bits/stdc++.h>
using namespace std;
#define mx 600005
struct dt{
    int x,y,id;
}qr[300005];
//vector<int>st[600005];
//vector<int>ed[600005];
//map<int,int>mp;
bool cmp(dt a, dt b){
    if(a.y==b.y)return a.x<b.x;
    return a.y < b.y;
}
int main()
{
    int n; scanf("%d",&n);
//    set<int>q;
    for(int i=1; i<=n; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        qr[i].x = x;
        qr[i].y = y;
        qr[i].id = i;
//        q.insert(x);
//        q.insert(y);
    }

    sort(qr+1,qr+n+1,cmp);

//    set<int>:: iterator ww;
//    int k=0;
//    for(ww=q.begin(); ww!=q.end(); ww++){
//        mp[*ww] = ++k;
//    }
//
//    int N = k;

//    for(int i=1; i<=n; i++){
//        int x,y,id;
//        x = qr[i].x;
//        y = qr[i].y;
//        id = qr[i].id;
//        st[mp[x]].push_back(i);
//        ed[mp[y]].push_back(i);
//    }

    int a = -1, b = -1;
//    set<int>s;
//    set<int>:: iterator it,jt,kt;
//    k = 0;
    for(int i=1; i<n; i++){
        if(qr[i].y==qr[i+1].y){
            if(qr[i].x<=qr[i+1].x){
                a = qr[i+1].id;
                b = qr[i].id;
                break;
            }
        }
        else{
            if(qr[i].x>=qr[i+1].x){
                a = qr[i].id;
                b = qr[i+1].id;
                break;
            }
        }
    }

    printf("%d %d\n",a,b);

    return 0;
}

