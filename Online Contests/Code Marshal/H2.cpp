#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,res,cmax,amax,amin,ser,ser1,ser2,sum,sum1,sum2,p1,a,b,a1,b1;
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        scanf("%lld",&n);

        cmax=(n/3)-1;
        amax=n-3;
        //amin=((n-cmax)/2)+1;
        amin=amax-(2*cmax)+2;

        if(amax%2==1)
        {
            p1=(amax/2)+1;
            sum1=(p1*p1);
            p1=(amin/2);
            sum2=(p1*p1);
            sum = sum1-sum2;
        }
        else
        {
            p1=(amax/2);
            sum1=(p1*p1)+p1;
            p1=(amin/2)-1;
            sum2=(p1*p1)+p1;
            sum = sum1-sum2;
        }

        a = ((n-1)/2)+1;
        b = ((n-cmax)/2)+1;

        ser1 = (a*(a+1))/2;
        ser2 = (b*(b-1))/2;
        ser = ser1-ser2;
        ser = 2*ser;

        if(n%2==1)
        {
            ser = ser-a;
            if((cmax-1)%2==1){
                ser = ser-b;
            }
        }
        else
        {
            if(cmax%2==1){
                ser = ser-b;
            }
        }
        /*if(n%2==0)
        {
            if(cmax%2==0)
            {
                ser1 = (a*(a+1))/2;
                ser2 = (b*(b-1))/2;
                ser = ser1-ser2;
                ser = 2*ser;
            }
            else
            {
                b1=b-1;
                ser1 = (a*(a+1))/2;
                ser2 = (b1*(b1-1))/2;
                ser = ser1-ser2;
                ser = 2*ser;
                ser += b;
            }
        }
        else
        {
            if(cmax%2==0)
            {
                a1=a-1;
                b1=b-1;
                ser1 = (a1*(a1+1))/2;
                ser2 = (b1*(b1-1))/2;
                ser = ser1-ser2;
                ser = 2*ser;
                ser += a;
                ser += b;
            }
            else
            {
                a1=a-1;
                ser1 = (a1*(a1+1))/2;
                ser2 = (b*(b-1))/2;
                ser = ser1-ser2;
                ser = 2*ser;
                ser += a;
            }
        }*/

        res = (sum+cmax)-ser;

        if(kase<t)
            printf("Case %d: %lld\n\n",kase,res);
        else
             printf("Case %d: %lld\n",kase,res);
    }

    return 0;
}


