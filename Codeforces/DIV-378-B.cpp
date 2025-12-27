#include<bits/stdc++.h>
using namespace std;
#define mx 100000
struct dt
{
    int lf,rg;
} st[mx+5];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int slf=0,srg=0;

        for(int i=0; i<n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            st[i].lf=x;
            st[i].rg=y;
            slf+=x;
            srg+=y;
        }



        int beauty=abs(slf-srg);
        int maxx=beauty;
        int ans=-1;
        for(int i=0; i<n; i++)
        {
            int x=st[i].lf;
            int y=st[i].rg;
            int tmlf=slf-x;
            int tmrg=srg-y;
            tmlf+=y;
            tmrg+=x;
            int d=abs(tmlf-tmrg);
            if(d>maxx)
            {
                maxx=d;
                ans=i+1;
            }
        }

        if(maxx>beauty){
            printf("%d\n",ans);
        }
        else{
            printf("0\n");
        }
    }

    return 0;

}
