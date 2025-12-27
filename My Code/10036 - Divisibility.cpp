#include<bits/stdc++.h>
using namespace std;
int ans,n,k,a[10005];
bool vs[10005][105];
void fun(int p,int r)
{
    if(ans==1)return;

    if(p==n+1){
        if(r==0)ans=1;
        return;
    }

    if(vs[p][r])return;
    vs[p][r]=true;

    int v;

    v = (r+a[p])%k;
    if(v<0)v=k+v; // v = k-(-v);
    fun(p+1,v);

    v = (r-a[p])%k;
    if(v<0)v=k+v;
    fun(p+1,v);

}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&n,&k);

        for(int i=1; i<=n; i++)scanf("%d",&a[i]);

        ans=0;
        memset(vs,false,sizeof(vs));

        fun(1,0);

        if(ans==1)printf("Divisible\n");
        else printf("Not divisible\n");
    }
    return 0;
}
