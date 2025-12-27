#include<bits/stdc++.h>
using namespace std;
int n,a[55][55];
int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    //bool flag = true;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int v = a[i][j];

            if(v==1)continue;

            bool ase=false;

            for(int y=1; y<=n; y++)
            {
                for(int x=1; x<=n; x++)
                {
                    int u = a[i][y]+a[x][j];
                    if(u==v){
                        ase = true;
                        goto label;
                    }
                }
            }

            label:

            if(ase==false)
            {
                printf("No\n");
                return 0;
            }
        }
    }

    printf("Yes\n");

    return 0;
}
