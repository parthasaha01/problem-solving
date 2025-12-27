#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
double a[mx];
void precalc()
{
    for(int i=1; i<=mx; i++)
        a[i]=a[i-1]+log10(i);
}
int count_digit(int n, int base)
{
    if(n==0) return 1;
    double sum=a[n]/log10(base);
    return floor(sum)+1;
}
int main()
{
    precalc();
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        int n,base;
        scanf("%d%d",&n,&base);
        printf("Case %d: %d\n",kase,count_digit(n,base));
    }
    return 0;
}
