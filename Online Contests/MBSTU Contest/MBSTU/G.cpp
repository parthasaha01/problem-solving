#include<bits/stdc++.h>
using namespace std;
int ara[2005];

int main()
{
 int n, d;

 scanf("%d %d", &n, &d);

 for(int i = 0; i < n; i++)
        scanf("%d", &ara[i]);

 int cnt = 0;

 for(int i = 1; i < n; i++){
    if(ara[i] <= ara[i - 1]){
        int dif = ara[i - 1] - ara[i] + 1;
        int res = dif/d;
        if(dif % d != 0)
            res++;
        ara[i] += (res * d);
        cnt += res;
    }
 }

 printf("%d\n",cnt);
}
