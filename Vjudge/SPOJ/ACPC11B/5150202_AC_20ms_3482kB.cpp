#include<bits/stdc++.h>
using namespace std;
long int a[1005],b[1005];
int main()
{
    long int T,N,M,i,j,res,flag,minn,high,low,mid,diff,item;

    scanf("%ld",&T);

    while(T--)
    {
        scanf("%ld",&M);
        for(i=0; i<M; i++){
            scanf("%ld",&a[i]);
        }
        scanf("%ld",&N);
        for(i=0; i<N; i++){
            scanf("%ld",&b[i]);
        }
        sort(a,a+M);
        sort(b,b+N);
        flag=0;
        //low=1;
        minn=100000007;
        for(i=0; i<M; i++)
        {
            item=a[i];
            low=0;
            high=N-1;

            while(low<=high)
            {
                mid=(low+high)/2;

                if(item==b[mid]){
                    flag=1;
                    minn=0;
                    break;
                }
                else if(item>b[mid]){
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            if(flag)
                break;

            diff=abs(item-b[mid]);
            minn=min(minn,diff);

            if(low>=N)
                low=N-1;
            diff=abs(item-b[low]);
            minn=min(minn,diff);

            if(high<0)
                high=0;
            diff=abs(item-b[high]);
            minn=min(minn,diff);

        }

        printf("%ld\n",minn);
    }

    return 0;
}
