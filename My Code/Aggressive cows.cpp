#include<bits/stdc++.h>
using namespace std;
long int a[100005];
int main()
{
    long int T,N,C,i,j,res,low,high,mid,sum,cnt;

    scanf("%ld",&T);

    while(T--)
    {
        scanf("%ld %ld",&N,&C);

        for(i=0; i<N; i++){
            scanf("%ld",&a[i]);
        }
        sort(a,a+N);

        high=a[N-1]-a[0];
        low=a[1]-a[0];
        res=0;

        while(high>=low)
        {
            mid=(high+low)/2.0;
            cnt=1;
            sum=a[0]+mid;
            for(i=0; i<N; i++)
            {
                if(a[i]>=sum){
                    ++cnt;
                    sum=a[i]+mid;
                }
            }
            if(cnt>=C){
                res=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        printf("%ld\n",res);

    }

    return 0;
}
