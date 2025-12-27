#include<bits/stdc++.h>
using namespace std;
#define mx 100005
long int a[mx];
int main()
{
    long int n,Min,res,i,j,k,cnt,flag,pos1,pos2,diff1,diff2,Max;

    scanf("%ld",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%ld",&a[i]);
    }
    pos1=0;
    pos2=0;
    cnt=0;
    res=-1;
    Min=a[1];
    Max=a[1];
    for(i=1; i<=n; i++)
    {

        diff1=abs(Min-a[i]);
        diff2=abs(Max-a[i]);
        if(diff1==0 || diff2==0)
        {
            ++cnt;
            if(diff1==0)
            {
                pos1=i;
            }
            if(diff2==0)
            {
                pos2=i;
            }

        }
        else if(diff1>1 || diff2>1)
        {
            if(diff1>1)
            {
                //printf("diff1 i=%ld res=%ld cnt=%ld pos1=%ld pos2-%ld min=%ld max=%ld\n",i,res,cnt,pos1,pos2,Min,Max);
                res=max(res,cnt);
                pos1=pos1+1;
                cnt=i-pos1+1;
                /*if(a[i]-a[i-1]==1){
                    pos1=i-1;
                }*/
                pos1=i-1;
                Min=a[pos1];

                if(a[i]>=Max)
                {
                    Max=a[i];
                    pos2=i;
                }
            }
            else
            {
                //printf("diff2 i=%ld res=%ld cnt=%ld pos1=%ld pos2-%ld min=%ld max=%ld\n",i,res,cnt,pos1,pos2,Min,Max);
                res=max(res,cnt);
                pos2=pos2+1;
                cnt=i-pos2+1;
                pos2=i-1;
                Max=a[pos2];

                if(a[i]<=Min)
                {
                    Min=a[i];
                    pos1=i;
                }
            }

        }
        else
        {
            if(a[i]<Min){
                pos1=i;
            }
            if(a[i]>Max){
                pos2=i;
            }

            if(a[i]<=Min)
            {
                Min=a[i];
            }
            if(a[i]>=Max)
            {
                Max=a[i];
            }
            ++cnt;
        }

        //printf("i=%ld cnt=%ld a[i]=%ld\n",i,cnt,a[i]);
    }

    res=max(res,cnt);

    printf("%ld\n",res);

    return 0;
}
