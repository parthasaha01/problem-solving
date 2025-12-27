#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    long int T, x, y, diff, result, len;

    scanf("%ld",&T);

    while(T--)
    {
        scanf("%ld %ld",&x, &y);

        diff = y-x;

        len=sqrt((double)diff);

        if(diff == 0)
            result=0;
        else if(len*len == diff)
            result=len*2-1;
        else if((len*len+len) < diff)
            result=len*2+1;
        else
            result=len*2;

           printf("%ld\n",result);
    }

        return 0;
}
