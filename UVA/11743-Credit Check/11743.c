#include<stdio.h>
int main()
{
    long int T,x,i,j,a[4],dbl,und,sum,rem;

    scanf("%ld",&T);
    for(i=1; i<=T; i++)
    {
        dbl=0;
        und=0;
        for(j=0; j<4; j++)
        {
            scanf("%ld",&a[j]);
            x=1;
            while(a[j] != 0)
            {
                rem=a[j]%10;
                a[j]=a[j]/10;

                if(x%2 == 0)
                {
                    rem=2*rem;
                    dbl += ( (rem%10) + ((rem/10)%10) );
                }
                else
                    und += rem;
                ++x;
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
