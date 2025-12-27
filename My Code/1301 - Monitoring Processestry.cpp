#include<bits/stdc++.h>
using namespace std;
int b[50005];
struct dt{
    int x,y;
}a[50005];
bool cmp(dt p,dt q)
{
    if(p.x==q.x){
        return p.y<q.y;
    }
    else{
        return p.x<q.x;
    }
}
int BinarySearch(int v,int n)
{
    int lo=0;
    int hi=n-1;
    int ans=0;
    //printf("lo=%d hi=%d\n",lo,hi);
    while(lo<=hi)
    {
        int md=(lo+hi)/2;
        ans=md;
        printf("lo=%d hi=%d md=%d b=%d v=%d\n",lo,hi,md,b[md],v);

        if(b[md]==v){
            hi=md-1;
        }
        else if(b[md]>v){
            hi=md-1;
        }
        else{
            lo=md+1;
        }

    }

    printf("ans=%d\n",ans);

    if(ans<=0) return ans;
    if(b[ans]>=v) return ans;
    return ans+1;
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
            b[i]=a[i].y;
        }

        sort(b,b+n);
        sort(a,a+n,cmp);

        int lo=1;
        int hi=n;
        int ans=0;
        while(lo<=hi)
        {
            int md=(hi+lo)/2;
            int k=md;

            bool flag=true;
            printf("k=%d:\n",k);
            for(int i=0; i<n; i++)
            {
                int u=a[i].x;
                int v=a[i].y;
                int psu=BinarySearch(u,n);
                int psv=BinarySearch(v+1,n);

                int ps=psv-psu;
                //ps=max(1,ps);
                printf("u=%d psu=%d v=%d psv=%d ps=%d\n\n",u,psu,v+1,psv,ps);
                if(ps>k){
                    flag=false;
                    break;
                }
            }
            if(flag){
                printf("for k=%d is possible.\n",k);
                hi=md-1;
                ans=md;
            }
            else{
                lo=md+1;
            }
        }

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
*/

