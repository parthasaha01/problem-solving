#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    scanf("%d",&k);
    int m=1;
    int cnt = 0;
    while(1)
    {
        int sum = 0;
        int n = m;
        while(n!=0)
        {
            int r = n%10;
            sum+=r;
            if(sum>10)break;
            n/=10;
        }

        if(sum==10)cnt++;

        if(cnt==k){
            printf("%d\n",m);
            return 0;
        }

        m++;
    }

    return 0;
}

