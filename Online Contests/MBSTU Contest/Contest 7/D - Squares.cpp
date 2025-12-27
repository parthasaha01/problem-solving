#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    int n,k,a[55];

    while(scanf("%d%d",&n,&k)==2)
    {
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }

        sort(a,a+n,cmp);

        if(k>n){
            printf("-1\n");
            continue;
        }

        int x=a[k-1];
        int y=a[k-1];

        printf("%d %d\n",x,y);
    }

    return 0;

}
