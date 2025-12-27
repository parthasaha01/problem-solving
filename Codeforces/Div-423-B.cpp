#include<bits/stdc++.h>
using namespace std;
string ss[105];
int a[105][105];
int main()
{
    int n,m;

    scanf("%d%d",&n,&m);

    for(int i=0; i<n; i++)
    {
        cin>>ss[i];
    }

    bool flag=false;
    int cnt=0;

    int up=0,down=0,left=0,right=0;

    //int x1,x2,y1,y2,x3,x4,y3,y4;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(ss[i][j]=='B')
            {
                cnt++;
                a[i+1][j+1]=1;
            }
            else
            {
                a[i+1][j+1]=0;
            }
        }
    }

    if(cnt==0)
    {
        printf("1\n");
        return 0;
    }
    if(cnt==n*m)
    {
        if(n==m)
        {
            printf("0\n");
        }
        else
        {
            printf("-1\n");
        }
        return 0;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]==1)
            {
                up=i;
                //x1=i; y1=j;
                goto labelup;
            }
        }
    }

    labelup:

    for(int i=n; i>=1; i--)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]==1)
            {
                down=i;
                //x2=i; y2=j;
                goto labeldown;
            }
        }
    }

    labeldown:

    for(int j=1; j<=m; j++)
    {
        for(int i=1; i<=m; i++)
        {
            if(a[i][j]==1)
            {
                left=j;
                //x3=i; y3=j;
                goto labelleft;
            }
        }
    }

    labelleft:

    for(int j=m; j>=1; j--)
    {
        for(int i=1; i<=m; i++)
        {
            if(a[i][j]==1)
            {
                right=j;
                //x4=i; y4=j;
                goto labelright;
            }
        }
    }

    labelright:

    int row,col;

    row = down-up+1;
    col = right-left+1;

    int sz = max(row,col);

    if(sz>n || sz>m)
    {
        printf("-1\n");
        return 0;
    }

    int sum = sz*sz;
    int ans = sum-cnt;

    printf("%d\n",ans);

    return 0;
}
