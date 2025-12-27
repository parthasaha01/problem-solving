#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long int
ll a[505][505];
int main()
{
    ll n;

    while(scanf("%I64d",&n)==1)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%I64d",&a[i][j]);
            }
        }
        ll x,y;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(a[i][j]==0)
                {
                    x=i;
                    y=j;
                    goto label;
                }
            }
        }

        label:

        if(n==1)
        {
            printf("1\n");
        }
        else
        {
            //printf("x=%I64d y=%I64d\n",x,y);

            ll sum=0;
            if(x==1)
            {
                for(int i=1; i<=n; i++)
                {
                    sum+=a[2][i];
                }
            }
            else
            {
                for(int i=1; i<=n; i++)
                {
                    sum+=a[1][i];
                }
            }

            ll ase=0;

            for(int i=1; i<=n; i++)
            {
                ase+=a[x][i];
            }

            ll need=sum-ase;

            //printf("sum=%I64d ase=%I64d need=%I64d\n",sum,ase,need);

            if(need<1)
            {
                printf("-1\n");
                continue;
            }

            a[x][y]=need;
            bool flag=true;
            for(int i=1; i<=n; i++)
            {
                ll cnt=0;
                for(int j=1; j<=n; j++)
                {
                    cnt+=a[i][j];
                }

                if(cnt!=sum)
                {
                    flag=false;
                    break;
                }
            }

            if(flag==false)
            {
                //printf("row\n");
                printf("-1\n");
                continue;
            }
            else
            {
                for(int i=1; i<=n; i++)
                {
                    ll cnt=0;
                    for(int j=1; j<=n; j++)
                    {
                        cnt+=a[j][i];
                    }
                    if(cnt!=sum)
                    {
                        flag=false;
                        break;
                    }
                }

                if(flag==false)
                {
                    //printf("col\n");
                    printf("-1\n");
                    continue;
                }
                else
                {
                    ll cnt=0;
                    for(int i=1; i<=n; i++)
                    {
                        cnt+=a[i][i];
                    }

                    if(cnt!=sum)
                    {
                        flag=false;
                    }

                    if(flag==false)
                    {
                        //printf("d1\n");
                        printf("-1\n");
                        continue;
                    }
                    else
                    {
                        ll cnt=0;
                        //int j;
                        for(int i=1,j=n; i<=n; i++,j--)
                        {
                            cnt+=a[i][j];
                        }

                        if(cnt!=sum)
                        {
                            flag=false;
                        }

                        if(flag==false)
                        {
                            //printf("d2\n");
                            printf("-1\n");
                            continue;
                        }
                        else
                        {
                            printf("%I64d\n",need);
                            continue;
                        }
                    }
                }
            }
        }

    }

    return 0;
}

