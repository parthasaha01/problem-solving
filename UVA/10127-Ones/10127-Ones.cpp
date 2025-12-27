#include<cstdio>
using namespace std;
int main()
{
    int n, res, num, rem;

    while(scanf("%d", &n)==1)
    {
        res=1;
        num=0;

        while(1)
        {
            num += 1;
            rem=num%n;
            if(!rem)
                break;

            num = rem*10;
            ++res;

        }

        printf("%d\n", res);
    }

    return 0;
}
