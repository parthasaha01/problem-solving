#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[1500];
    int n,m,t,kase,x,y,delay,trips,total;
    scanf("%d",&kase);

    while(kase--)
    {
        scanf("%d %d %d",&n,&t,&m);

        for(int i=0; i<m; i++)
        {
            scanf("%d",&a[i]);
        }

        y=m-1;
        x=y-n;
        delay = 0;
        while(x>=0)
        {
            delay += max(0,a[x]+2*t-a[y]);
            y=x;
            x=y-n;
        }

        total = delay+a[m-1]+t;

        if(m%n==0){
            trips= m/n;
        }
        else{
            trips = (m/n)+1;
        }

        printf("%d %d\n",total,trips);
    }

    return 0;
}
