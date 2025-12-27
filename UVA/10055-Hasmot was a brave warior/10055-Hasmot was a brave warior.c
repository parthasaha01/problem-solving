#include<stdio.h>
int main()
{
    unsigned long int a, b, minus_,temp;

   while(scanf("%lu %lu", &a, &b) == 2)
   {
        if(a<b)
        {
            minus_ = b-a;
        }
        else
        {
            temp = a;
            a = b;
            b = temp;

            minus_ = b-a;
        }

        printf("%lu\n", minus_);

   }
    return 0;
}
