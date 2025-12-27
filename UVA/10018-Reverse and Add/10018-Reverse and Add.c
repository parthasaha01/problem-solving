#include<stdio.h>
int main()
{
    long long int N,P,num,num1,rem,rev,i;

    scanf("%lld", &N);

    for(i=1; i<=N; i++)
    {
        scanf("%lld", &num);
        num1=num;
        rev=0;
        P=-1;
        while(num1 != rev)
        {
            num1=num+rev;
            num=num1;
            rev=0;
            while(num1 != 0)
            {
                rem = num1%10;
                num1=num1/10;
                rev=rev*10+rem;
            }
            num1=num;
            P++;
        }
        printf("%lld %lld\n",P,rev);
    }

    return 0;
}
