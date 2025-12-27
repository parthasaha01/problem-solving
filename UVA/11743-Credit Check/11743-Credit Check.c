#include<stdio.h>
int main()
{
    long int T,x,i,j,a[4],dbl,und,sum,rem;

    scanf("%ld",&T);
    for(x=1; x<=T; x++)
    {
        dbl=0;
        und=0;
        for(j=0; j<4; j++)
        {
            scanf("%ld",&a[j]);
        }
        for(j=0; j < 4; j++)
        {
            i=1;
            while(a[j] != 0)
            {
                rem=a[j]%10;
                a[j]=a[j]/10;

                if(i%2 == 0)
                {
                    rem=2*rem;
                    dbl += ( (rem%10) + ((rem/10)%10) );
                }
                else
                    und += rem;
                ++i;
            }
        }

        sum=dbl+und;

        if((sum%10)==0)
            printf("Valid\n");
        else
            printf("Invalid\n");
    }

    return 0;
}
