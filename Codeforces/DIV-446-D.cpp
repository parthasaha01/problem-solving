#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 4194310
ll n,a[50],b[50],s[50];
ll v[mx+5],vs[23][mx],flag;
void fun(int pos,int mask,vector<int>p)
{
    if(flag==1)return;

    if(pos==n){
        flag=1;
        for(int i=0; i<n; i++)
        {
            if(i==n-1)printf("%d\n",a[p[i]]);
            else printf("%d ",a[p[i]]);
        }
        return;
    }

    if(vs[pos][mask]==1)return;
    vs[pos][mask]=1;

    for(int i=0; i<n; i++){
        if((mask&(1<<i))==0){
            int tmask = mask;
            tmask |= (1<<i);
            ll u = v[tmask];
            if(u==s[pos]&&pos!=n-1)continue;
            p.push_back(i);
            fun(pos+1,tmask,p);
        }
    }
}
int main()
{
    scanf("%I64d",&n);

    s[0]=0;
    for(int i=0; i<n; i++){
        scanf("%I64d",&a[i]);
        if(i==0)s[i]=a[i];
        else s[i] = s[i-1]+a[i];
    }

    for(int mask=1; mask<(1<<n); mask++)
    {
        ll sum=0;
        for(int i=0; i<n; i++){
            if(mask&(1<<i)){
                sum+=a[i];
            }
        }
        v[mask]=sum;
    }
    vector<int>p;
    fun(0,0,p);

    if(flag==0){
        printf("-1\n");
    }

    return 0;
}
