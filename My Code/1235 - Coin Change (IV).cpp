#include<bits/stdc++.h>
using namespace std;
int n,hn,k,a[40],sv,su;
vector<int>vv,uu;
void fun1(int pos,int sum)
{
    if(pos==hn){ vv.push_back(sum); return; }

    fun1(pos+1,sum);
    fun1(pos+1,sum+a[pos]);
    fun1(pos+1,sum+a[pos]+a[pos]);
}
void fun2(int pos,int sum)
{
    if(pos==n){ uu.push_back(sum); return; }

    fun2(pos+1,sum);
    fun2(pos+1,sum+a[pos]);
    fun2(pos+1,sum+a[pos]+a[pos]);
}
bool check(int v)
{
    int lo=0; int hi=su-1;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(uu[md]==v)return true;
        else if(uu[md]<v)lo=md+1;
        else hi=md-1;
    }
    return false;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        vv.clear(); uu.clear();

        scanf("%d%d",&n,&k);
        for(int i=0; i<n; i++)scanf("%d",&a[i]);
        sort(a,a+n);
        hn = n/2;

        fun1(0,0);
        fun2(hn,0);

        sort(uu.begin(),uu.end());

        sv = vv.size();
        su = uu.size();

        bool flag=false;
        for(int i=0; i<sv; i++)
        {
            int v = vv[i];
            flag = check(k-v);
            if(flag==true)break;
        }

        if(flag==true)printf("Case %d: Yes\n",ks);
        else printf("Case %d: No\n",ks);
    }
    return 0;
}
