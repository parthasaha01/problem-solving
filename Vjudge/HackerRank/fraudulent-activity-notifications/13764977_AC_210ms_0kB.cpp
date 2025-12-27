#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int a[mx+5];
int fr[mx+5];
//void init(int nd,int b,int e)
//{
//    if(b==e)
//    {
//        tree[nd].push_back(a[b]);
//        return;
//    }
//    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;
//    init(lf,b,md);
//    init(rg,md+1,e);
//    MergeNode(nd,lf,rg);
//}
//int query(int nd,int b,int e,int x,int y,int v)
//{
//    if(b>y||e<x)
//        return 0;
//    if(b>=x&&e<=y)
//    {
//        int cnt = LowerBound(nd,v);
//        return cnt;
//    }
//    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;
//    int p1 = query(lf,b,md,x,y,v);
//    int p2 = query(rg,md+1,e,x,y,v);
//    return p1+p2;
//}

int main()
{
    int n,d;
    scanf("%d%d",&n,&d);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        //ar[i] = a[i];
    }

    //init(1,1,n);

    //sort(ar+1,ar+n+1);

    int k;
    if(d&1)
    {
        k = (d/2)+1;
        int cnt = 0;
        for(int i=1; i<=d; i++){
            fr[a[i]]++;
        }
        for(int y=d+1,x=1; y<=n; y++,x++)
        {
            int sum = 0;
            int ret=0;
            for(int v=0; v<=200; v++){
                if(sum+fr[v]>=k){
                    ret = v;
                    break;
                }
                sum+=fr[v];
            }

            if(a[y]>=2*ret)cnt++;
            fr[a[x]]--;
            fr[a[y]]++;
        }
        printf("%d\n",cnt);
    }
    else
    {
        k = (d/2);
        int cnt = 0;
        for(int i=1; i<=d; i++){
            fr[a[i]]++;
        }
        for(int y=d+1,x=1; y<=n; y++,x++)
        {
            int sum = 0;
            int ret1=0;
            for(int v=0; v<=200; v++){
                if(sum+fr[v]>=k){
                    ret1 = v;
                    break;
                }
                sum+=fr[v];
            }

            sum = 0;
            int ret2=0;
            for(int v=0; v<=200; v++){
                if(sum+fr[v]>=k+1){
                    ret2 = v;
                    break;
                }
                sum+=fr[v];
            }

            int ret = ret1+ret2;

            if(a[y]>=ret)cnt++;
            fr[a[x]]--;
            fr[a[y]]++;
        }

        printf("%d\n",cnt);
    }

    return 0;
}

