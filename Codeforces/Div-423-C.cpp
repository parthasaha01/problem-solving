#include<bits/stdc++.h>
using namespace std;
#define mx 2000002
int ps[2000005];
char ss[2000005];
string tt[100005];
struct dt
{
    int b,e,x;
}st[1000005];
bool cmp(dt pp,dt qq)
{
    if(pp.b==qq.b){
        return pp.e>qq.e;
    }
    return pp.b < qq.b;
}
int main()
{
    int n;
    scanf("%d",&n);

    int p=0;
    int xxx=0;
    for(int i=1; i<=n; i++)
    {
        cin>>tt[i];
        int sz = tt[i].size();
        int k; scanf("%d",&k);
        for(int j=1; j<=k; j++)
        {
            int x; scanf("%d",&x);
            x--;
            ++p;
            st[p].b=x;
            st[p].e=x+sz-1;
            xxx = max(xxx,st[p].e);
            st[p].x=i;
        }
    }

    sort(st+1,st+p+1,cmp);

    for(int i=0; i<mx; i++){
        ps[i]=i;
        ss[i]=0;
    }

    int ses=-1;
    for(int i=1; i<=p; i++)
    {
        int b,e,x;
        b = st[i].b;
        e = st[i].e;
        x = st[i].x;

        if(e<=ses)continue;

        int bg = max(b,ses+1);

        for(int u=bg; u<=e; u++)
        {

            int v = u-b;
            ss[u]=tt[x][v];
        }
        ses = max(ses,e);
    }


    for(int i=0; i<=xxx; i++)
    {
        if(ss[i]==0)
        {
            ss[i]='a';
        }
    }
    ss[xxx+1]='\0';

    puts(ss);

    return 0;
}

