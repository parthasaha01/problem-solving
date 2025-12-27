#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(a==0 && b==0)printf("NO\n");
        else if(abs(b-a)<=1)printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
