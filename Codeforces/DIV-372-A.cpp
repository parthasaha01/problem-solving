#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n,c;
    while(scanf("%d%d",&n,&c)==2)
    {
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }
        int cnt=1;
        for(int i=1; i<n; i++){
            if(a[i]-a[i-1]<=c){
                cnt++;
            }
            else{
                cnt=1;
            }
        }

        printf("%d\n",cnt);
    }

    return 0;
}
