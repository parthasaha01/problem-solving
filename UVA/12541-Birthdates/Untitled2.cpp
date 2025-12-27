#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 110
string nam[MAXN];
int d[MAXN],m[MAXN],y[MAXN];
bool cmp(int a,int b)
{
    if(y[a]!=y[b])  return y[a]<y[b];
    if(m[a]!=m[b])  return m[a]<m[b];
    if(d[a]!=d[b])  return d[a]<d[b];
}
int main()
{
    //freopen("/home/moor/Code/input","r",stdin);
    int n,pos1,pos2;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;++i)
            cin>>nam[i],scanf("%d%d%d",&d[i],&m[i],&y[i]);
        pos1=pos2=1;
        for(int i=2;i<=n;++i)
        {
            if(cmp(pos1,i))
                pos1=i;
            if(cmp(i,pos2))
                pos2=i;
        }
        cout<<nam[pos1]<<'\n'<<nam[pos2]<<'\n';

    }
}
