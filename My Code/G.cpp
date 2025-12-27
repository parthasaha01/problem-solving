#include<bits/stdc++.h>
using namespace std;
long int arr[1005];
long int pw[1005];
int flag[1005];
int main()
{
    long int T,n,i,j,test,k,sum,res,temp,p;

    scanf("%ld",&T);

    for(test=1; test<=T; test++)
    {
        scanf("%ld",&n);
        res=0;
        sum=0;

        memset(arr,0,sizeof(arr));
        memset(pw,0,sizeof(pw));
        memset(flag,0,sizeof(flag));

        for(i=0,j=0; i<n; i++)
        {
            scanf("%ld %ld",&k,&p);

            if(flag[p]==0)
            {
                pw[j]=p;
                flag[p]=1;
                j++;
            }
            arr[p]+=k;
            sum+=k;
        }
        sort(pw,pw+j);

        /*printf("sum=%ld\n",sum);
        for(i=0; i<j; i++)
        {
            printf("%ld %ld\n",arr[pw[i]],pw[i]);
        }*/

        for(i=0; i<j; i++)
        {
            temp=sum*pw[i];
            if(temp>res)
            {
                res=temp;
            }
            sum = sum-arr[pw[i]];
        }

        printf("Case %ld: %ld\n",test,res);

    }

    return 0;
}
