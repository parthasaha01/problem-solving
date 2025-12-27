#include<cstdio>
using namespace std;
int main()
{
    int T, total=0;
    double a, b, c, d;

    scanf("%d", &T);

    while(T--)
    {
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

        if(((a+b+c <= 125.0) || (a <= 56.0 && b <= 45.0 && c <= 25.0) ) && d <= 7.0)
        {
            printf("1\n");
            ++total;
        }
        else
            printf("0\n");
    }
    printf("%d\n", total);

    return 0;
}
