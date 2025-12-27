#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a, b, c, d, i, sum, temp;

    while(scanf("%d %d %d %d", &a, &b, &c, &d))
    {
        if(!a && !b && !c && !d)
            break;

        sum=1080;       // (2*360)+(1*360)=1080

        temp = a-b;             //clock-wise. so a to b is (a-b)
        if(temp< 0)
            temp += 40;
        sum += temp*9;

        temp = c-b;             //counter clock-wise. so b to c is (c-b)
        if(temp< 0)
            temp += 40;
        sum += temp*9;

        temp=c-d;           //clock-wise. so c to d is (c-d)
        if(temp< 0)
            temp += 40;
        sum += temp*9;

        printf("%d\n", sum);
    }

    return 0;
}
