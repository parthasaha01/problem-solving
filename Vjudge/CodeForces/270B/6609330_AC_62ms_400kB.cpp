#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n,x;

    while(scanf("%d",&n)==1)
    {
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
            //a[x]=i;
        }

        int cnt=1;

        for(int i=1; i<n; i++)
        {
            if(a[i]>a[i-1]){
                cnt++;
            }
            else{
                cnt=1;
            }
        }

        printf("%d\n",n-cnt);
    }

    return 0;
}
