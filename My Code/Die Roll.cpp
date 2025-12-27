#include<bits/stdc++.h>
using namespace std;
int getGCD(int a,int b)
{
    if(b==0) return a;
    getGCD(b,a%b);
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        int maxx=max(a,b);
        int n=6-maxx+1;
        int t=6;

        if(n==t){
            printf("1/1\n");
            continue;
        }

        int gcd=getGCD(n,t);

        printf("%d/%d\n",n/gcd,t/gcd);
    }

    return 0;
}
