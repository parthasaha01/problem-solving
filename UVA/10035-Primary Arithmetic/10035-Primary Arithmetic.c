#include<stdio.h>
int main()
{
    long long int num1,num2,rem1,rem2,count_,carry;

    while(scanf("%lld %lld", &num1, &num2)==2 && (num1!=0 || num2!=0))
    {
        count_=0;
        carry=0;
        while(num1!=0 || num2!=0)
        {
            rem1=num1%10;
            rem2=num2%10;

            if((rem1+rem2+carry)>9)
            {
                count_++;
                carry= 1;
            }
            else
            {
                carry=0;
            }
            num1=num1/10;
            num2=num2/10;
        }

        if(count_ == 0)
        {
            printf("No carry operation.\n");
        }
        else if(count_ == 1)
        {
            printf("%lld carry operation.\n",count_);
        }
        else
        {
            printf("%lld carry operations.\n",count_);
        }
    }

    return 0;
}
