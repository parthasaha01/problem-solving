#include<bits/stdc++.h>
using namespace std;
int ans[10005];
int divisor(int n)
{
    int cnt=0;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            cnt++;
        }
    }
    return cnt;
}
void precalculate()
{
    ans[1]=1;

    for(int i=2; i<=10000; i++){
        ans[i]=ans[i-1]+divisor(i);
    }
}
int main()
{
    //precalculate();

    int n;
    while(scanf("%d",&n)==1)
    {
        int cnt=0;
        for(int i=1; i<=n; i++){
            cnt+=divisor(i);
        }
        printf("%d\n",cnt);
    }

    return 0;
}

