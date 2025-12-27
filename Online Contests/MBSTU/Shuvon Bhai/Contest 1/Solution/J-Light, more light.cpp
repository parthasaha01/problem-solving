#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    long long n, sqt;

    while(scanf("%lld", &n) && n)
    {
        sqt = sqrt(n);

        if((sqt*sqt) == n)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}

