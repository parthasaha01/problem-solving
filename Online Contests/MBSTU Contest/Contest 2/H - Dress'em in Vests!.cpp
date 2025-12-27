#include<bits/stdc++.h>
using namespace std;
#define mx 100005
struct type
{
    int need,low,high;
} p[mx];
int b[mx],sb[mx],se[mx];
int main()
{
    int n,m,x,y,a,k,cnt;

    while(scanf("%d%d%d%d",&n,&m,&x,&y)==4)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a);
            p[i].need = a;
            p[i].low = max(1,a-x);
            p[i].high = a+y;
        }

        for(int i=1; i<=m; i++)
        {
            scanf("%d",&b[i]);
        }

        /*for(int i=1; i<=n; i++)
        {
            printf("%d: %d (%d-%d)\n",i,p[i].need,p[i].low,p[i].high);
        }*/

        k=1;
        cnt=0;
        //int q=1;
        for(int i=1; i<=m && k<=n;)
        {

            if(b[i]>=p[k].low && b[i]<=p[k].high)
            {
                ++cnt;
                //cout << k << " " << i << " " << cnt << endl;
                sb[cnt]=k;
                se[cnt]=i;
                i++;
                k++;
            }
            else
            {
                if(b[i]>p[k].low)
                {
                    k++;
                }
                else
                {
                    i++;
                }
            }
            //cout << k << " " << i << " " << cnt << endl;
            //q++;
        }
        //printf("K=%d i=%d\n",k,q);

        printf("%d\n",cnt);
        for(int i=1; i<=cnt; i++)
        {
            printf("%d %d\n",sb[i],se[i]);
        }
    }

    return 0;
}
