#include<bits/stdc++.h>
using namespace std;
#define mx 200005
struct dt{
    int xx,yy,zz,id,fg;
}st[mx+5];
bool cmp(dt p, dt q){
    return p.id<q.id;
}
vector<int>vv;
bool winner(int i,int j)
{
    if((st[i].xx>st[j].xx) && (st[i].yy>st[j].yy))return true;
    if((st[i].xx>st[j].xx) && (st[i].zz>st[j].zz))return true;
    if((st[i].yy>st[j].yy) && (st[i].zz>st[j].zz))return true;

    return false;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            st[i].xx = x;
            st[i].yy = y;
            st[i].zz = z;
            st[i].id = i;
        }

        for(int r=1; r<=10; r++)
        {
            random_shuffle(st+1,st+n+1);
            for(int i=1; i<=n; i++)st[i].fg = false;
            bool abar = false;
            int kk=0;

            for(int i=1; i<=n; i++)
            {
                bool flag = st[i].fg;
                if(flag==false)
                {
                    for(int j=1; j<=n; j++)
                    {
                        if(i!=j)
                        {
                            if(winner(i,j))
                            {
                                st[i].fg = true;
                                break;
                            }
                        }
                        kk++;
                    }
                    if(kk>10000000){
                        abar = true;
                        break;
                    }
                }
            }

            if(abar==false){
                break;
            }
        }

        sort(st+1,st+n+1,cmp);
        vv.clear();
        for(int i=1; i<=n; i++){
            int id = st[i].id;
            if(st[id].fg==false){
                vv.push_back(id);
            }
        }

        int sz = vv.size();
        printf("%d\n",sz);
        for(int i=0; i<sz; i++){
            if(i==sz-1)printf("%d\n",vv[i]);
            else printf("%d ",vv[i]);
        }

    }

    return 0;
}
