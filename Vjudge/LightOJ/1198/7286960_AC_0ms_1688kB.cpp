#include<bits/stdc++.h>
using namespace std;
int a[55],b[55];
bool va[55],vb[55];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0; i<n; i++)
        {
            scanf("%d",&b[i]);
        }
        sort(a,a+n);
        sort(b,b+n,cmp);
        int ans=0;

        memset(va,false,sizeof(va));
        memset(vb,false,sizeof(vb));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(a[i]>b[j]&&vb[j]==false)
                {
                    ans+=2;
                    vb[j]=true;
                    va[i]=true;
                    break;
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            if(va[i]==false)
            {
                for(int j=0; j<n; j++)
                {
                    if(a[i]==b[j] && vb[j]==false)
                    {
                        ans+=1;
                        va[i]=true;
                        vb[j]=true;
                        break;
                    }
                }
            }
        }

        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}
/*
10
9
5 5 5 5 5 5 5 5 5
1 2 3 4 5 6 7 8 9
4
2 3 4 6
1 4 5 6
6
1 2 3 3 3 4
1 5 4 4 4 4
*/
