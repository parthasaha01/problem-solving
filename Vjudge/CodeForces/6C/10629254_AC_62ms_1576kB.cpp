#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int n,a[mx+5],lf[mx],rg[mx],res[mx];
int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }

    int p=0;
    for(int i=1; i<=n; i++)
    {
        lf[i]=p;
        p+=a[i];
    }

    int q=0;
    for(int i=n; i>=1; i--)
    {
        rg[i]=q;
        q+=a[i];
    }

    for(int i=1; i<=n; i++)
    {
        if(lf[i]<=rg[i]){
            res[i]=1;
        }
        else{
            res[i]=2;
        }
    }

    int alice=0,bob=0;

    for(int i=1; i<=n; i++)
    {
        if(res[i]==1){
            alice++;
        }
        else{
            bob++;
        }
    }

    printf("%d %d\n",alice,bob);

    return 0;
}
