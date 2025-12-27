#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
double a[10005];
int main()
{
    long int T,N,F,sum;
    double maxx,low,mid,high,res;
    scanf("%ld",&T);
    while(T--)
    {
        maxx=0;
        scanf("%ld",&N);
        scanf("%ld",&F);
        for(int i=0; i<N; i++){
            scanf("%lf",&a[i]);
            a[i]=pi*a[i]*a[i];
            maxx=max(maxx,a[i]);
        }

        low=0.0;
        high=maxx;
        F=F+1;

        while(abs(low-high)>0.0001)
        {
            mid=(high+low)/2.0;
            sum=0;
            for(int i=0; i<N && sum<=F; i++)
            {
                sum+=floor(a[i]/mid);
            }

            if(sum>=F){
                low=mid;
            }
            else{
                high=mid;
            }
        }
        printf("%0.4lf\n",mid);

    }

    return 0;
}
