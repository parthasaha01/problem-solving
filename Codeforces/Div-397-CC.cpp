#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,a,b;

    while(cin>>k>>a>>b)
    {
        int ra = a-a/k*k;
        int rb = b-b/k*k;

        if(a/k+b/k==0 || (ra>b/k*k || rb>a/k*k)){
            printf("-1\n");
        }
        else{
            printf("%d\n",(a/k)+(b/k));
        }

    }

    return 0;

}

