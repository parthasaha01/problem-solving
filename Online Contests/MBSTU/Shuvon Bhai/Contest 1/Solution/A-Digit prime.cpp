#include<bits/stdc++.h>
using namespace std;
#define N 1000000
#define sqN 1000
map<long int, long int>num;
map<long int, long int>dprime;
map<long int, long int>flag;
void seive()
{
    long int i,j,Count=0,sum,n;

    dprime[2] = ++Count;
    flag[2]=1;
    num[1]=1; // 1 is not prime


    for(i=3;i<=sqN; i+=2)
    {
        if(num[i]==0)
        {
            sum=0;
            n=i;
            while(n!=0)
            {
                sum+=(n%10);
                n/=10;
            }
            if(sum%2==0)
            {
                if(sum==2)
                {
                    dprime[i] = ++Count;
                    flag[i]=1;
                }
                else
                    dprime[i]=Count;
            }
            else if(num[sum]==0)
            {
                dprime[i] = ++Count;
                flag[i]=1;
            }
            else
            {
                dprime[i]=Count;
            }

            for(j=i*i; j<=N; j+=(i+i))
            {
                num[j]=1;
            }
        }
        else
        {
            dprime[i]=Count;
        }
    }
    for(i=sqN+1; i<N; i+=2)
    {
        if(num[i]==0)
        {
            sum=0;
            n=i;
            while(n)
            {
                sum+=(n%10);
                n/=10;
            }
            if(sum%2==0)
            {
                if(sum==2)
                {
                    dprime[i] = ++Count;
                    flag[i]=1;
                }
                else
                    dprime[i]=Count;
            }
            else if(num[sum]==0)
            {
                dprime[i] = ++Count;
                flag[i]=1;
            }
            else
            {
                dprime[i]=Count;
            }
        }
        else
        {
            dprime[i]=Count;
        }
    }
}
int main()
{
    seive();

    long int T,t1,t2,i,result,diff;

    scanf("%ld",&T);

    while(T--)
    {
        scanf("%ld %ld",&t1,&t2);
        diff = t2-t1;
        if(diff>1)
        {
            //printf("%ld %ld\n",num[t1],num[t2);

            if(t1%2==0 && t1!=2)
                t1=t1+1;
            if(t2%2==0)
                t2=t2-1;

            if(flag[t1]==1)
            {
                result = (dprime[t2]-dprime[t1])+1;
                //printf("if t1=%ld t2=%ld flag(t1)=%ld dprime[t1]=%ld dprime[t2]=%ld\n",t1,t2,flag[t1],dprime[t1],dprime[t2]);
            }
            else
            {
                result = dprime[t2]-dprime[t1];
                //printf("else t1=%ld t2=%ld flag(t1)=%ld dprime[t1]=%ld dprime[t2]=%ld\n",t1,t2,flag[t1],dprime[t1],dprime[t2]);
            }
        }
        else
        {
            if(diff==0)
            {
                if(flag[t1]==1)
                    result=1;
                else
                    result=0;
            }
            else    // diff==1
            {
                if(t2==2)
                {
                    result=1;
                }
                else if(t1==2 && t2==3)
                {
                    result=2;
                }
                else if((t2%2)==0)
                {
                    result=flag[t1];
                }
                else
                {
                    result=flag[t2];
                }
            }
        }

        printf("%ld\n",result);
    }

    return 0;
}
