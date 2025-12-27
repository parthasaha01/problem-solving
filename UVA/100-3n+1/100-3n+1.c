#include<stdio.h>
int main()
{
    long int i,j,temp,n,R,r;

    while(scanf("%ld %ld", &i,&j) == 2)
    {
        R=0;
        printf("%ld %ld",i,j);
        if(j<i)
        {
            temp=i;
            i=j;
            j=temp;
        }
        while(i <= j)
        {
            n=i;
            r=1;
            while(n != 1)
            {
                if(n%2 != 0)
                {
                    n=3*n+1;
                    r++;
                }
                else
                {
                    n=n/2;
                    r++;
                }
            }
            if(r > R)
            {
                R=r;
            }
            i++;
        }
        printf(" %ld\n",R);
    }

    return 0;
}
