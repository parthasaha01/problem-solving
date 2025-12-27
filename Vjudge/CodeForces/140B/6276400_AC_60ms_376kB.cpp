#include<bits/stdc++.h>
using namespace std;
int a[305][305],b[305];
int res[305];
struct data
{
    int v;
    int p;
} st[305];
bool cmp(int x, int y)
{
    return st[x].p < st[y].p;
}
int main()
{
    int n,x,cur,minn,idx;

    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&b[i]);
        }

        memset(res,0,sizeof(res));

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(a[i][j]!=i)
                {
                    int k;
                    for(k=1; k<=n; k++)
                    {
                        if(b[k]<=a[i][j] && b[k]!=i)
                        {
                            break;
                        }
                    }
                    if(b[k]==a[i][j])
                    {
                        res[i]=b[k];
                        break;
                    }
                }
            }
        }

        for(int i=1; i<=n; i++)
        {
            cout << res[i];
            if(i!=n)
                cout << " ";
        }
        cout << endl;


    }

    return 0;
}
