#include<bits/stdc++.h>
using namespace std;
struct type
{
    int v,div;
    bool prime;
} st[1001];
bool cmp(type x, type y)
{
    if(x.div==y.div)
    {
        return x.v > y.v;
    }

    return x.div < y.div;
}
void NumbserOfDivisor()
{
    for(int i=1; i<=1000; i++)
    {
        st[i].v=i;
        st[i].div=1;
        st[i].prime=true;
    }

    for(int i=2; i<=1000; i+=2)
    {
        int k=0;
        int n1=i;
        st[i].prime=false;
        while(n1%2==0)
        {
            k++;
            n1/=2;
        }
        st[i].div=k+1;
    }

    for(int i=3; i<=500; i+=2)
    {
        if(st[i].prime==true)
        {
            st[i].div=2;

            for(int j=i+i; j<=1000; j+=i)
            {
                st[j].prime=false;

                int k=0;
                int n1=j;

                while(n1%i==0)
                {
                    k++;
                    n1/=i;
                }
                st[j].div = st[j].div*(k+1);
            }
        }
    }

    for(int i=501; i<=1000; i+=2)
    {
        if(st[i].prime==true)
        {
            st[i].div=2;
        }
    }

    sort(st,st+1001,cmp);

    return;
}
int main()
{
    NumbserOfDivisor();

    int t,n;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",kase,st[n].v);
    }
    return 0;
}
