#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    int a[10005];
    scanf("%d",&T);
    for(int test=1; test<=T; test++)
    {
        int n;
        scanf("%d",&n);

        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }

        int num=1;
        int cnt=0;

        for(int i=0; i<n; i++){
            if(a[i]==num){
                num++;
            }
            else{
                cnt++;
            }
        }

        printf("Case %d: %d\n",test,cnt);
    }

    return 0;
}
