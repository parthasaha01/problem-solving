#include<stdio.h>
long min(long a, long b, long c)
{
   if(a<=b && a<=c)
     return a;
   else if(b<=a && b<=c)
     return b;
   else
     return c;
 }

long uglyNo(int n)
{
   long ugly[n+1];
   int i2=0,i3=0,i5=0;
   ugly[0]=1;
   int i;
   long next_2=2,next_3=3,next_5=5;
   for(i=1;i<n+1;i++)
   {
     //printf("%d %d %d\n",i2,i3,i5);
     ugly[i]=min(next_2,next_3,next_5);

   if(ugly[i]==next_2)
   {
     i2++;
     next_2=2*ugly[i2];
    }
   if(ugly[i]==next_3)
   {
     i3++;
     next_3=3*ugly[i3];
    }
   if(ugly[i]==next_5)
   {
     i5++;
     next_5=5*ugly[i5];
   }

  }
   return ugly[n-1];
 }

int main()
{
   long ans;
   ans=uglyNo(1500);
   printf("The 1500'th ugly number is %ld.\n",ans);

   return 0;
}
