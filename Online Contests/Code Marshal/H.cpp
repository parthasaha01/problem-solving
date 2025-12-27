#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,res,cmax,amax,amin,num,num1,num2,num3,rem,rem2,rem1,ser1,ser2,sum,sum1,sum2,r1;
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        //cin >> l >> n;
        scanf("%lld",&n);

        cmax=(n/3)-1;

        int flag=0;

        for(int i=1; i<=cmax; i++)
        {
            r1=n-1;
            amax=n-3;
            amin=(r1/2)+1;

            if(flag==0){
                num = amax-amin+1;
                num1 = num;
                flag=1;
            }

            num2 = amax-amin+1;

            if(num2!=num1){
                //num3=num2;
                break;
            //printf("partha\n");
            }
            num1=num2;
        }
        num3=num2;
        sum1 = ((num)*(num+1))/2;
        rem = num-cmax;

        ser1 = rem*num3;
        rem2=rem-1;
        ser2 = (rem2*(2*3+(rem2-1)*3))/2;

        sum2 = sum1-ser1 + ser2;

        printf("amax=%lld amin=%lld cmax=%lld\n",amax,amin,cmax);
        printf("num=%lld rem=%lld\n",num,rem);
        printf("sum1=%lld sum2=%lld\n",sum1,sum2);
        printf("ser1=%lld ser2=%lld\n",ser1,ser2);

        res=sum2;

        if(kase<t)
            printf("Case %d: %lld\n\n",kase,res);
        else
             printf("Case %d: %lld\n",kase,res);
    }

    return 0;
}

