#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define Max 100004
ll num[Max+2];
int a[1005];
void sieve()
{
    ll i,j,doubleI,k,m;
    //long long sum;
    double x,y,sum;

    num[1]=1LL;
    num[2]=3LL;

    for(i=4; i<=Max; i+=2)
    {
        k=0;
        j=i;
        while((j&1)==0)
        {
            k++;
            j = j>>1;   // j = j/2
        }
        k++;
        sum = (1<<k)-1;
        //sum = pow(2,k)-1;
        num[i]=sum;
    }

    //printf("%lld\n",num[10]);

    int HfMax=Max/2;

    for(i=3; i<=HfMax; i+=2)
    {
        if(num[i]==0)
        {
            num[i]=i+1;

            for(j=i+i; j<=Max; j+=i)
            {
                k=0;
                m=j;

                while((m%i)==0)
                {
                    k++;
                    m = m/i;   // j = j/2
                }
                k++;
                x=(double)i;
                y=(double)k;
                sum = (pow(x,y)-1)/(i-1);

                if(num[j] != 0)
                {
                    num[j] *= sum;
                }
                else
                {
                    num[j] = sum;
                }

            }
        }
    }

}
int main()
{
    sieve();
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);

        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }

        ll maxx=-1;
        int ans=10000000;

        for(int i=0; i<n; i++)
        {
            int x=a[i];
            ll psum=num[x]-x;
            //printf("x=%d psum=%lld\n",x,psum);
            if(psum>x)
            {
                int aban=psum-x;

                if(aban>maxx){
                    maxx=aban;
                    ans=x;
                }
                else if(aban==maxx){
                    if(x<ans){
                        ans=x;
                    }
                }
            }
        }

        if(maxx==-1)
        {
            printf("-1\n");
        }
        else{
            printf("%d %lld\n",ans,maxx);
        }
    }

    return 0;
}
