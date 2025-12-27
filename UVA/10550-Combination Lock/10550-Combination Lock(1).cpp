#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a, b, c, d, sum, temp;

    while(scanf("%d %d %d %d", &a, &b, &c, &d))
    {
        if(!a && !b && !c && !d)
            break;

        sum=120;

        temp=a-b;
        if(temp< 0)
            sum += temp+40;
        else
            sum += temp;

        temp=c-b;
        if(temp< 0)
            sum += temp+40;
        else
            sum += temp;

        temp=c-d;
        if(temp< 0)
            sum += temp+40;
        else
            sum += temp;

        printf("%d\n", sum*9);
    }

    return 0;
}
