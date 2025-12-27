#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 int main()
 {
     ll N,n,cnt,prev,sum,ser,i,k,sq,a,e,cur,diff;

     while(scanf("%lld",&N)==1 && N)
     {
         sq=sqrt((double)N);
         prev=N;
         sum=N;
         e=N;
         cnt=0;

         for(i=2; i<=sq; i++)
         {
             cur=(N/i);
             n=prev-cur;
             cnt+=n;
             sum+=(i*cur);
             a=(e-n+1);
             ser=(((2*a)+(n-1))*n)/2;
             sum+=(ser*(i-1));
             e=a-1;
             prev=cur;
         }

         n=N-(sq+cnt);
         if(n)
         {
             a=sq+1;

             for(k=1,i=a; k<=n;k++,i++){
                 sum+=(i*(N/i));
             }
         }
         sum = sum-1;
         printf("%lld\n",sum);
     }

     return 0;
 }
