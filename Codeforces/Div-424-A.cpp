#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[105];
int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }

    if(n==1)
    {
        printf("YES\n");
        return 0;
    }

    bool flag=true;
    for(int i=2; i<=n; i++)
    {
        if(a[i]!=a[i-1])
        {
            flag=false;
            break;
        }
    }
    if(flag==true)
    {
        printf("YES\n");
        return 0;
    }

    int p=1;
    a[0]=0;
    while(p<=n && a[p]>a[p-1])
    {
        p++;
    }

    if(p>n)
    {
        printf("YES\n");
        return 0;
    }

    //p--;

    while(p<=n && a[p]==a[p-1])
    {
        p++;
    }

    if(p>n)
    {
        printf("YES\n");
        return 0;
    }

//    if(a[p]>a[p-1])
//    {
//        printf("NO\n");
//        return 0;
//    }

    for(int i=p; i<=n; i++)
    {
        if(a[i]>=a[i-1])
        {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");



    //int inc=1,con=0,dec=0;

//    for(int i=2; i<=n; i++)
//    {
//        if(a[i]==a[i-1])
//        {
//            inc=0;
//            con=1;
//        }
//        if(a[i]>a[i-1])
//        {
//            if(inc==0)
//            {
//                printf("")
//            }
//        }
//    }
    return 0;

}
