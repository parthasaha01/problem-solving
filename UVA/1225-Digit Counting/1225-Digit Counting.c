#include<stdio.h>
int main()
{
    long int T,N,x,y,n,rem;

    scanf("%ld",&T);
    for(x=1; x<=T; x++)
    {
        int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0;
        scanf("%ld",&N);

        for(y=1; y <= N; y++)
        {
            n=y;
            while(n != 0)
            {
                rem=n%10;
                n=n/10;

                if(rem == 0)
                    ++a;
                else if(rem == 1)
                    ++b;
                else if(rem == 2)
                    ++c;
                else if(rem == 3)
                    ++d;
                else if(rem == 4)
                    ++e;
                else if(rem == 5)
                    ++f;
                else if(rem == 6)
                    ++g;
                else if(rem == 7)
                    ++h;
                else if(rem == 8)
                    ++i;
                else
                    ++j;
            }

        }
        printf("%d %d %d %d %d %d %d %d %d %d\n",a,b,c,d,e,f,g,h,i,j);
    }

    return 0;
}
