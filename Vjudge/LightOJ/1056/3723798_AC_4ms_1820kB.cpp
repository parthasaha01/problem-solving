#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,T;
    double angel,x;
    char ch;
    cin >> T;
    for(int test=1; test<=T; test++)
    {
        scanf("%d %c %d",&a,&ch,&b);
        angel=acos(double(a*a-b*b)/(a*a+b*b));
        x=400/((2*a)+(angel*sqrt(a*a+b*b)));
        printf("Case %d: %.10lf %.10lf\n",test,a*x,b*x);
    }

    return 0;
}
