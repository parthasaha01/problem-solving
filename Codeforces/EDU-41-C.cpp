#include<bits/stdc++.h>
using namespace std;
int a[5][205][205];
int xx[205][205],yy[205][205],ww[205][205];
int n,nn;
char ss[205];
vector<int>vv;
int fun(int u,int v,int x,int y)
{
    for(int i=1,p=1; p<=n; i++,p++)
    {
        for(int j=1,q=1; q<=n; j++,q++)
        {
            ww[i][j] = a[u][p][q];
        }
    }
    for(int i=1,p=1; p<=n; i++,p++)
    {
        for(int j=n+1,q=1; q<=n; j++,q++)
        {
            ww[i][j] = a[v][p][q];
        }
    }
    for(int i=n+1,p=1; p<=n; i++,p++)
    {
        for(int j=1,q=1; q<=n; j++,q++)
        {
            ww[i][j] = a[x][p][q];
        }
    }
    for(int i=n+1,p=1; p<=n; i++,p++)
    {
        for(int j=n+1,q=1; q<=n; j++,q++)
        {
            ww[i][j] = a[y][p][q];
        }
    }

    int cnt1=0;
    int cnt2=0;

    for(int i=1; i<=nn; i++)
    {
        for(int j=1; j<=nn; j++)
        {
            if(ww[i][j]!=xx[i][j])cnt1++;
            if(ww[i][j]!=yy[i][j])cnt2++;
        }
    }

    int cnt = min(cnt1,cnt2);
    return cnt;
}
int main()
{
    scanf("%d",&n);

    for(int k=1; k<=4; k++)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%s",&ss);
            for(int j=1; j<=n; j++)
            {
                //scanf("%d",&a[k][i][j]);
                a[k][i][j] = ss[j-1]-'0';
            }
        }
    }

//    for(int k=1; k<=4; k++)
//    {
//        for(int i=1; i<=n; i++)
//        {
//            //scanf("%s",&ss);
//            for(int j=1; j<=n; j++)
//            {
//                //scanf("%d",&a[k][i][j]);
//                printf("%d",a[k][i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
//    }

    int v,u;
    nn = 2*n;

    v = 0;
    for(int i=1; i<=nn; i++)
    {
        v = 1-v;
        u = v;
        for(int j=1; j<=nn; j++)
        {
            xx[i][j] = u;
            u = 1-u;
        }
    }

    v = 1;
    for(int i=1; i<=nn; i++)
    {
        v = 1-v;
        u = v;
        for(int j=1; j<=nn; j++)
        {
            yy[i][j] = u;
            u = 1-u;
        }
    }

//    for(int i=1; i<=nn; i++)
//    {
//        for(int j=1; j<=nn; j++)
//        {
//            printf("%d ",xx[i][j]);
//        }
//        printf("\n");
//    }

    vv.push_back(1);
    vv.push_back(2);
    vv.push_back(3);
    vv.push_back(4);

    int ans = 10000000;

    do
    {
        int cnt = fun(vv[0],vv[1],vv[2],vv[3]);
        ans = min(ans,cnt);
    }while(next_permutation(vv.begin(), vv.end()));

    printf("%d\n",ans);

    return 0;

}
