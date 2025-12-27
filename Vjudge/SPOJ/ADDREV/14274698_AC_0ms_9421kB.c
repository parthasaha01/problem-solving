#include<stdio.h>
 int ar[100],br[100],cr[100];
int main()
{
     int a,b,i,c,j,d,e,f,k,r,sum,h,m,x,y,z,n;
    scanf("%d",&a);
    for(i=1;i<=a;i++)
    {
        k=1;
        d=0;
        e=0;
        f=0;
        y=1;
        z=1;
        scanf("%d %d",&b,&c);
        while(b!=0)
        {
            r=b%10;
            ar[k]=r;
            k++;
            b=b/10;
        }
        for(j=1;j<=k-1;j++)
        {
            d=(d*10)+ar[j];
        }
        while(c!=0)
        {
            x=c%10;
            br[y]=x;
            y++;
            c=c/10;
        }
         for(h=1;h<=y-1;h++)
        {
            e=(e*10)+br[h];
        }
        sum=d+e;
        while(sum!=0)
        {
            n=sum%10;
            cr[z]=n;
            z++;
            sum=sum/10;
        }
         for(m=1;m<=z-1;m++)
        {
            f=(f*10)+cr[m];
        }
        printf("%d\n",f);
    }
    return 0;
}
