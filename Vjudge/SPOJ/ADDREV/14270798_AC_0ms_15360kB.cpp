#include<stdio.h>
int main()
{
    int i,t,n,a,rev,re,c,b,d,rev1,m,k;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        rev=0;
        re=0;
        rev1=0;
        scanf("%d%d",&n,&b);
        while(n!=0)
        {
            a=n%10;
            n=n/10;
            rev=rev*10+a;
        }
        while(b!=0)
        {
            c=b%10;
            b=b/10;
            re=re*10+c;
        }
        m=(rev+re);
        while(m!=0)
        {
            k=m%10;
            m=m/10;
            rev1=rev1*10+k;
        }
        printf("%d\n",rev1);
    }
    return 0;
}
