#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    char s[105];
    for(int test=1; test<=t; test++)
    {
        int sz;
        scanf("%d\n",&sz);
        gets(s);
        //puts(s);
        int cnt = 0;
        for(int i=0; i<sz; i++){

            if(s[i]=='.'){
                ++cnt;
                i += 2;
            }
        }

        printf("Case %d: %d\n",test,cnt);
    }

    return 0;
}
