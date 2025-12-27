#include<bits/stdc++.h>
using namespace std;
int ara[1000005];
int main()
{
    int test, tc = 0;

    scanf("%d", &test);

    while(test--){
        int n;
        scanf("%d" ,&n);

        int minn=99999999;

        for(int i = 0; i < n; i++)
            scanf("%d",&ara[i]);

        int cnt=0;

        for(int i = n-1; i >=0; i--)
        {
            if(ara[i]>minn){
                cnt++;
            }
            minn=min(minn,ara[i]);
        }

        printf("Case #%d: %d\n",++tc,cnt);
    }
    return 0;
}

