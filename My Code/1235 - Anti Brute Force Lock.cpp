#include<bits/stdc++.h>
using namespace std;
string ss[505];
map<string,int>mp;
int par[505];
struct dt{ int u,v,w; };
vector<dt>vv;
bool cmp(dt x, dt y)
{
    return x.w<y.w;
}
int findparent(int x)
{
    if(par[x]==x) return x;
    return par[x]=findparent(par[x]);
}
void Unionparent(int x,int y)
{
    par[findparent(y)] = findparent(x);
}

int kruskal(int n)
{
    for(int i=0; i<=n; i++) par[i]=i;
    int sum=0;

    sort(vv.begin(),vv.end(),cmp);

    bool flag = false;

    for(int i=0; i<vv.size(); i++)
    {
        dt top = vv[i];

        if(flag==true){
            if(top.u==0 || top.v==0)continue;
        }
        if(top.u==0 || top.v==0)flag=true;
        int parU = findparent(top.u);
        int parV = findparent(top.v);

        if(parU!=parV){
            Unionparent(parU,parV);
            sum += top.w;
        }
    }

    vv.clear();

    return sum;
}
int fun(string a,string b)
{
    int sum=0;
    for(int i=0; i<4; i++)
    {
        int d1 = a[i]-'0';
        int d2 = b[i]-'0';
        if(d1<d2)swap(d1,d2);
        int c1 = abs(d1-d2);
        int c2 = (10-d1)+d2;
        int c = min(c1,c2);

        sum += c;
    }
    return sum;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);

        ss[0] = "0000";
        for(int i=1; i<=n; i++)
        {
            cin >> ss[i];
            mp[ss[i]]=i;
        }

        for(int i=0; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(i==j)continue;
                int w = fun(ss[i],ss[j]);
                dt xx; xx.u=i; xx.v=j; xx.w=w;
                vv.push_back(xx);
            }
        }

        int ans = kruskal(n+1);

        printf("%d\n",ans);
    }
    return 0;
}
