#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int a[505];
int main()
{
     int n,k;

     while(scanf("%d%d",&n,&k)==2)
     {
         for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
         }

         int ans=0;

         for(int i=1;i<n;i++)
         {
             if(a[i]+a[i-1]<k){
                int p=(k-(a[i]+a[i-1]));
                a[i]+=p;
                ans+=p;
             }
         }

         printf("%d\n",ans);
         for(int i=0; i<n-1; i++){
            printf("%d ",a[i]);
         }
         printf("%d\n",a[n-1]);
     }

     return 0;
}

