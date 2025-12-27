#include<bits/stdc++.h>
using namespace std;
#define mx 300005
struct dt
{
    int type,x;
} st[mx];
int a[mx],t[mx],lr[mx],tp[mx];
int main()
{
    int n,q;
    int unread;

    scanf("%d%d",&n,&q);
    int k=1;
    for(int i=0; i<q; i++)
    {
        scanf("%d%d",&st[i].type,&st[i].x);

        if(st[i].type==3)
        {
            t[k++]=st[i].x;
        }
    }


    unread=0;
    int type,x;
    int total=0;
    int p=0;
    int j=1;
    for(int i=0; i<q; i++)
    {
        type=st[i].type;
        x=st[i].x;

        if(type==1)
        {
            unread++;
            a[x]++;
            printf("%d\n",unread);
            total++;
            tp[total]=x;

        }
        else if(type==2)
        {
            unread -= a[x];
            a[x]=0;
            printf("%d\n",unread);
            lr[x]=total;

        }
        else
        {
            p++;
            if(t[p]>t[p-1])
            {
                for(; j<=x; j++)
                {
                    int u=tp[j];

                    if(j>lr[u])
                    {
                        unread--;
                        lr[u]=j;
                        a[u]--;
                    }
                }
            }

            printf("%d\n",unread);
        }
    }

    return 0;
}
