#include<cstdio>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define sqN 1000
long int prime[80000];
long int diff[80000];
long int cdiff[80000];
long int p,d,k,srtp,endp,L,U;
void seive()
{
    map<long int, long int>num;

    long int i,j;
    p=0,d=0;

    prime[p]=2;
    p++;

    for(i=3; i<=sqN; i+=2)
    {
        if(num[i]==0)
        {
            prime[p] = i;
            diff[d++] = prime[p]-prime[p-1];
            p++;

            for(j=i*i; j<=N; j+=(i+i))
            {
                num[j]=1;
            }
        }
    }

    for(i=sqN+1; i<=N; i+=2)
    {
        if(num[i]==0)
        {
            prime[p]=i;
            diff[d++]=prime[p]-prime[p-1];
            p++;
        }
    }

    //printf("%ld %ld",p,d);
}
void search_index()
{
    long int i,j;

    srtp=endp=-1;

    for(i=0; i<p; i++)
    {
        if(prime[i]>=L)
        {
            srtp=i;
            j=i;
            break;
        }
    }
    if(prime[srtp]>U)
    {
        srtp=-1;
        return;
    }
    for(i=j;i<p;i++)
    {
        if(prime[i]>U)
        {
            endp=i-1;
            break;
        }
    }
}
void copy_diff()
{
    long int i;
    k=0;

    //printf("srtp=%ld endp=%ld\n",srtp,endp);

    for(i=srtp; i<endp; i++)
    {
        cdiff[k++]=diff[i];
        //printf("%ld ",cdiff[k-1]);
    }
    //printf("\n");
    sort(cdiff, cdiff+k);

    /*for(i=0;i<k;i++)
    {
        printf("%ld ",cdiff[i]);
    }
    printf("\n"); */
}
long int find_champ()
{
    long int Max,Lmax,i,m,n,res,x=0;
    Max=0;
    Lmax=0;

    for(i=0;i<k;)
    {
        m=cdiff[i];
        n=0;

        while(cdiff[i]==m)
        {
            n++;
            i++;
            x++;

            if(i==k)
                break;
        }
        if(n>=Max)
        {
            Lmax=Max;
            Max=n;
            res=cdiff[i-1];
        }
    }

    if(Max==Lmax || x==0)
    {
        return 0;
    }
    else
        return res;

}
int main()
{
    seive();

    long int T,flag;

    scanf("%ld",&T);

    while(T--)
    {
        scanf("%ld %ld",&L,&U);

        search_index();

        if(srtp==-1 || endp==-1)
        {
            flag=0;
        }
        else
        {
            copy_diff();

            flag = find_champ();
        }

        if(flag==0)
        {
            printf("No jumping champion\n");
        }
        else
        {
            printf("The jumping champion is %ld\n",flag);
        }
    }

    return 0;
}
