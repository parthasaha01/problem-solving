#include<bits/stdc++.h>
using namespace std;
int n,m;
//void check()
//{
//    int a[3005][3005],b[3005][3005],s[9000005],r,c;
//
//    r=1; for(int i=1; i<=n; i++)r*=3;
//    c=1; for(int i=1; i<=m; i++)c*=3;
//
//    for(int i=1,v=0,k=0; i<=r; i++)
//    {
//        for(int j=1; j<=c; j++)
//        {
//            a[i][j]=++v;
//            s[++k] = a[i][j];
//        }
//    }
//
//    int ans=0;
//
//    while(1)
//    {
//        ans++;
//
//        for(int j=1,k=0; j<=c; j++)
//        {
//            for(int i=1; i<=r; i++)
//            {
//                b[i][j] = s[++k];
//            }
//        }
//
//        int flag=true;
//
//        for(int i=1; i<=r; i++)
//        {
//            for(int j=1; j<=c; j++)
//            {
//                if(a[i][j]!=b[i][j])
//                {
//                    flag=false;
//                    goto label;
//                }
//            }
//        }
//
//        label:
//
//        if(flag)break;
//
//        for(int i=1,k=0; i<=r; i++)
//        {
//            for(int j=1; j<=c; j++)
//            {
//                s[++k] = b[i][j];
//            }
//        }
//    }
//
//    printf("ans=%d\n",ans);
//}
int GCD(int m,int n)
{
    if(n==0)return m;
    return GCD(n,m%n);
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&m,&n);
        int ans = (m+n)/GCD(m,n);
        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}
