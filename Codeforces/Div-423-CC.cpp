#include<bits/stdc++.h>
using namespace std;
#define mx 2000002
int ps[2000005];
char ss[2000005],tt[2000005];
int main()
{
    int n;
    scanf("%d",&n);


    for(int i=0; i<mx; i++){
        ps[i]=i;
        ss[i]=0;
    }
    int xxx=0;
    for(int i=1; i<=n; i++)
    {

        int k; scanf("%s %d",&tt,&k);
        //printf("%s %d\n",tt,k);
        int sz = strlen(tt);
        for(int j=1; j<=k; j++)
        {
            int x; scanf("%d",&x);
            x--;

            int st=x;
            int ed=x+sz-1;

            xxx = max(xxx,ed);

            for(int u=ps[st]; u<=ed; )
            {
                int v = u-st;
                ss[u]=tt[v];
                ps[u]=max(ps[u],ed+1);
                u = ps[u+1];
            }
        }
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

