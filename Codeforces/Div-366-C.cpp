#include<bits/stdc++.h>
using namespace std;
#define mx 300005
int a[mx],lr[mx],tp[mx];
vector<int>c[300005];
int main()
{
    int n,q;
    int unread;

    while(scanf("%d%d",&n,&q)==2)
    {
        memset(a,0,sizeof(a));
        memset(tp,0,sizeof(tp));
        memset(lr,0,sizeof(lr));

        unread=0;
        int type,x;
        int total=0;
        int j=1;

        for(int i=0; i<q; i++)
        {
            scanf("%d%d",&type,&x);

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
                for( ;j<=x; j++)
                {
                    int u=tp[j];

                    if(j>lr[u])
                    {
                        unread--;
                        lr[u]=j;
                        a[u]--;
                    }
                }

                printf("%d\n",unread);
            }
        }
    }

    return 0;
}
