#include<bits/stdc++.h>
using namespace std;
int a[105];
int gr[10005][10];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);

    int sum=0;

    for(int i=1; i<=k; i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }

    sort(a+1,a+k+1,cmp);

    int x=1;
    int cnt=0;

    for(int i=1; i<=k; i++)
    {
        int v=a[i];
        if(v>=4)
        {
            //int cnt=0;
            int rr = v/4;

            for(int j=x,kk=1; kk<=rr && j<=n; j++,kk++)
            {
                for(int m=3; m<=6; m++)
                {
                    gr[j][m]=1;
                    a[i]--;
                    cnt++;
                }
                x++;
            }
        }
        else
        {
            break;
        }
    }

    sort(a+1,a+k+1,cmp);

    int y=1;

    for(int i=1; i<=k; i++)
    {
        int v = a[i];

        if(v%4==0 && v!=0)
        {

            if(v%4==0)
            {
                int rr = v/4;

                for(int j=y,kk=1; kk<=rr && j<=n; j++,kk++)
                {
                    gr[j][1]=1; gr[j][2]=1; gr[j][7]=1; gr[j][8]=1;
                    y++;
                    a[i]-=4;
                    cnt+=4;
                }
            }
//            else
//            {
//                int rr = v/4;
//
//                for(int j=y,k=1; k<=rr && j<=n; j++)
//                {
//                    gr[j][1]=1; gr[j][2]=1; gr[j][7]=1; gr[j][8]=1;
//                    y++;
//                    a[i]-=4;
//                }
//
//            }

        }
    }

    sort(a+1,a+k+1,cmp);

    int yy=0;

    for(int i=1; i<=k; i++)
    {
        int v = a[i];
        if(v==0)continue;

        //if(v%2==0)
        {
            int rr = v/2;
            for(int j=y,kk=1;  kk <=rr && j<=n; kk++)
            {
                if(yy==0)
                {
                    gr[j][1]=1;
                    gr[j][2]=1;
                    a[i]--;
                    a[i]--;
                    yy = 1-yy;
                    cnt+=2;
                }
                else
                {
                    gr[j][7]=1;
                    gr[j][8]=1;
                    a[i]--;
                    a[i]--;
                    yy = 1-yy;
                    j++;
                    y++;
                    cnt+=2;
                }
            }
        }

    }

    sort(a+1,a+k+1,cmp);

    int p=1;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=8; j++)
        {
            if(gr[i][j]==0)
            {
                if(a[p]<=0)continue;
                if(j==1)
                {
                    gr[i][j]=1;
                    a[p]--;
                    if(a[p]>)
                }
                else if(j==3)
                {

                }
                else if(j==7)
                {

                }
            }
        }
    }

}
