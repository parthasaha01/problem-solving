#include<bits/stdc++.h>
using namespace std;
int a[15],b[15];
int p[15],q[15];
int lf[15],rg[15];
int main()
{
    int t; scanf("%d",&t);

    lf[1]=lf[2]=lf[4]=lf[6]=lf[8]=lf[9] = 1; // lift 1
    rg[1]=rg[3]=rg[5]=rg[7]=rg[9] = 1; // lift 2

    for(int ks=1; ks<=t; ks++)
    {
        int c,l,x;
        scanf("%d%d%d",&c,&l,&x);

        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(p,0,sizeof(p));
        memset(q,0,sizeof(q));

        int n,m; scanf("%d%d",&n,&m);

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            p[a[i]]=1;
        }
        sort(a+1,a+n+1);

        for(int i=1; i<=m; i++){
            scanf("%d",&b[i]);
            q[b[i]]=1;
        }
        sort(b+1,b+m+1);

        if(c==x){
            printf("Happy Emma!\n");
            continue;
        }


        if(l==1)
        {
            if(lf[x]==1){
                printf("Happy Emma!\n");
            }
            else{

                if(c<x)
                {
                    bool flag = true;
                    for(int v=x+1; v<=9; v++)
                    {
                        if(p[v]==1){
                            flag = false;
                            break;
                        }
                    }

                    if(flag)printf("Happy Emma!\n");
                    else printf("Dhat! Shobshomoy amar shathei ken emon hoy!\n");
                }
                else
                {
                    bool flag = true;
                    for(int v=x-1; v>=1; v--)
                    {
                        if(p[v]==1){
                            flag = false;
                            break;
                        }
                    }

                    if(flag)printf("Happy Emma!\n");
                    else printf("Dhat! Shobshomoy amar shathei ken emon hoy!\n");
                }
            }
        }
        else
        {
            if(rg[x]==1){
                printf("Happy Emma!\n");
            }
            else{
                if(c<x)
                {
                    bool flag = true;
                    for(int v=x+1; v<=9; v++)
                    {
                        if(q[v]==1){
                            flag = false;
                            break;
                        }
                    }

                    if(flag)printf("Happy Emma!\n");
                    else printf("Dhat! Shobshomoy amar shathei ken emon hoy!\n");
                }
                else
                {
                    bool flag = true;
                    for(int v=x-1; v>=1; v--)
                    {
                        if(q[v]==1){
                            flag = false;
                            break;
                        }
                    }

                    if(flag)printf("Happy Emma!\n");
                    else printf("Dhat! Shobshomoy amar shathei ken emon hoy!\n");
                }
            }
        }
    }

    return 0;
}
