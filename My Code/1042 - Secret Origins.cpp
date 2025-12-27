#include<bits/stdc++.h>
using namespace std;
int b[100];
int main()
{
    long int T,N,n,cnt,one,res,zero,mn,i,j,k,p,digit;

    scanf("%ld",&T);

    for(int test=1; test<=T; test++)
    {
        scanf("%ld",&N);
        n=N;
        cnt=0;
        k=0;
        while(n!=0)
        {
            b[k++]=(n%2);
            n/=2;
        }
        digit=k;

        /*for(k=digit-1; k>=0; k--){
            printf("%d ",b[k]);
        }
        printf("\n");*/

        one=0;
        zero=0;
        for(i=0; i<digit; i++)
        {
            if(b[i]==0)
                ++zero;
            else
                break;
        }
        for(; i<digit; i++){
            if(b[i]==1)
                ++one;
            else
                break;
        }
        b[i-1]=0;
        --one;
        /*for(k=digit-1; k>=0; k--){
            printf("%d ",b[k]);
        }
        printf("\n");*/
        if(i==digit)
        {
            b[digit]=1;
            ++digit;
        }
        else
        {
            b[i]=1;
        }

        mn=min(one,zero);
        p=i-2;
        //printf("zero=%ld one=%ld mn=%ld p=%ld\n",zero,one,mn,p);

        for(j=0; j<mn; j++)
        {
            b[p-j]=0;
            b[j]=1;
        }

        /*for(k=digit-1; k>=0; k--){
            printf("%d ",b[k]);
        }
        printf("\n");*/

        res=0;

        for(i=0; i<digit; i++)
        {
            if(b[i]){
                res+=pow(2,i);
            }
        }

        printf("Case %d: %ld\n",test,res);
    }

    return 0;
}
