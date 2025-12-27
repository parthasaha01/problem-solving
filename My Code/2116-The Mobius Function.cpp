#include<bits/stdc++.h>
using namespace std;
int prime[10005],mob[10005];
void mobius()
{
    for(int i=1; i<=10000; i++)mob[i]=1;

    mob[1]=1;

    for(int i=2; i<=10000; i++){
        if(prime[i]==0){
            mob[i]=-1;
            for(int j=i+i; j<=10000; j+=i){
                if(j%(i*i)==0)mob[j]=0;
                mob[j]*=(-1);
                prime[j]=1;
            }
        }
    }

}
int main()
{
    mobius();
    int n,flag=0;
    while(scanf("%d",&n))
    {
        if(n==-1)break;
        if(flag)printf("\n");
        flag=1;
        printf("M(%d) = %d\n",n,mob[n]);
    }
    return 0;
}
