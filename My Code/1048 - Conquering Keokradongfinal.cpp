#include<bits/stdc++.h>
using namespace std;
long int a[1005],sum[1005],arr[1005];
int main()
{
    long int T,N,K,res,cnt,k,low,high,flag,maxx,minn,i,j,jhigh,ct,x,n,diff,mid,sub,c,d;

    scanf("%ld",&T);

    for(int test=1; test<=T; test++)
    {
        scanf("%ld %ld",&N,&K);
        K+=1;
        N+=1;
        low=0;
        high=0;
        d=N;
        c=K;
        for(i=1; i<=N; i++)
        {
            scanf("%ld",&a[i]);
            low=max(low,a[i]);
        }
        high=N*low;
        //printf("low=%ld high=%ld\n",low,high);
        //int p=10;
        while(high>low)
        {
            mid=(high+low)/2;
            sum[1]=0;
            cnt=1 ;
            flag=1;
            for(i=1,k=1; i<=N; i++)
            {
                if(sum[k]+a[i]<=mid)
                {
                    sum[k]+=a[i];
                }
                else
                {
                    ++cnt;
                    if(cnt>K)
                    {
                        flag=0;
                        break;
                    }
                    k=k+1;
                    sum[k]=a[i];
                }

                if(N-i==K-k){
                    //printf("mid=%ld i=%ld k=%ld\n",mid, i, k);
                    break;
                }
            }
            if(flag)
            {
                for(j=1; j<=k; j++)
                {
                    arr[j]=sum[j];
                }
                d=k;
                c=i;
                //printf("low=%ld high=%ld mid=%ld\n",low,high,mid);
                high=mid;
                res=mid;
            }
            else
            {
                low=mid+1;
            }

        }
        //printf("c=%ld d=%ld\n",c,d);
        for(j=d+1,i=c+1; j<=K && i<=N; j++)
        {
            arr[j]=a[i];
            i++;
        }
        printf("Case %ld: %ld\n",test,res);
        for(i=1; i<=K; i++)
        {
            printf("%ld\n",arr[i]);
        }
    }
    return 0;
}

