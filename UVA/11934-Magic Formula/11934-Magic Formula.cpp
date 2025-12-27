#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long int a, b, c, d, L, x, flag, value;

    while(scanf("%ld %ld %ld %ld %ld", &a, &b, &c, &d, &L)==5)
    {
        if(!a && !b && !c && !d && !L)
            break;

        flag=0;

        for(x=0; x<=L; x++)
        {
            value = a*(x*x) + b*x + c;

            if(!(value%d))
                ++flag;
        }

        printf("%ld\n", flag);
    }

    return 0;
}
