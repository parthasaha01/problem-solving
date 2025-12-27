#include<bits/stdc++.h>
using namespace std;
#define nn 200005
char s[30],ss[30];
int a[nn+5];
int sum[4*nn][2];
void update(int nd,int b,int e,int x,int v)
{
    if(b==x && e==x){
        sum[nd][0]=sum[nd][1]=v;
        return;
    }

    int lf = 2*nd, rg=2*nd+1, md = (b+e)/2;
    if(x<=md)update(lf,b,md,x,v);
    else update(rg,md+1,e,x,v);

    sum[nd][0] = max(sum[lf][0],sum[rg][0]);
    sum[nd][1] = min(sum[lf][1],sum[rg][1]);
}
int query(int nd,int b,int e,int x,int y,int k)
{
    if(b>y || e<x){
        if(k==0)return -1000000000;
        else return 1000000000;
    }
    if(b>=x && e<=y)return sum[nd][k];
    int lf = 2*nd, rg=2*nd+1, md = (b+e)/2;
    int p1 = query(lf,b,md,x,y,k);
    int p2 = query(rg,md+1,e,x,y,k);
    if(k==0)return max(p1,p2);
    else return min(p1,p2);
}
int main()
{
    int q; scanf("%d",&q);
    int fr=100003,bk=100003;
    int flag = 0;
    while(q--)
    {
        scanf("%s %s",s,ss);
        //printf("%s %s\n",s,ss);

        if(s[0]=='I')
        {
            int v; scanf("%d",&v);

            if(flag==0)
            {
                fr=100003, bk = 100003;
                a[fr]=v;
                update(1,1,nn,fr,v);
                flag = 1;
                continue;
            }

            if(ss[0]=='F')
            {
                fr--;
                a[fr]=v;
                update(1,1,nn,fr,v);
            }
            else
            {
                bk++;
                a[bk]=v;
                update(1,1,nn,bk,v);
            }


        }
        else if(s[0]=='E')
        {
            if(ss[0]=='F')
            {
                //update(1,1,nn,fr,0);
                fr++;

            }
            else
            {
                //update(1,1,nn,bk,0);
                bk--;
            }
        }
        else if(ss[0]=='F')
        {
            int ans = a[fr];
            printf("%d\n",ans);
        }
        else if(ss[0]=='B')
        {
            int ans = a[bk];
            printf("%d\n",ans);
        }
        else if(ss[1]=='a')
        {
            int ans = query(1,1,nn,fr,bk,0);
            printf("%d\n",ans);
        }
        else
        {
            int ans = query(1,1,nn,fr,bk,1);
            printf("%d\n",ans);
        }
    }

    return 0;
}
