#include<bits/stdc++.h>
using namespace std;
int a[100005],p[100005];
int gr[100005],n,k;
int check(int x)
{
    memset(gr,0,sizeof(gr));

    for(int i=1; i<=n; i++)
    {
       // int key;
        if(a[i]%x==0){
            int kk = a[i]/x;
            //int ss = kk*x;
            int key = kk*x;
            gr[key]++;
            if(gr[key]>k)return 0;
        }
        else{
            //int r = a[i]%x;
            int kk = a[i]/x;
            //int ss = kk*x;
            int key = kk*x;
            gr[key]++;
            if(gr[key]>k)return 0;
        }
    }
    return 1;
}
void result(int x)
{
    for(int i=1; i<=n; i++)
    {
       // int key;
        if(a[i]%x==0){
            int kk = a[i]/x;
            //int ss = kk*x;
            int key = kk*x;
            p[i] = key;
        }
        else{
            //int r = a[i]%x;
            int kk = a[i]/x;
            //int ss = kk*x;
            int key = kk*x;
            p[i] = key;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);

    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }

    int lo = 1;
    int hi = 100000;
    int ans = 1;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;

        if(check(md)==1)
        {
            lo = md+1;
        }
        else
        {
            ans = md;
            hi = md-1;
        }
    }

    printf("ans=%d\n",ans);

    result(ans);

    for(int i=1; i<=n; i++){
        if(i==n)printf("%d\n",p[i]);
        else printf("%d ",p[i]);
    }

    return 0;
}
