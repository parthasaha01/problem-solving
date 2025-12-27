#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[105][105];
bool cmp(int x, int y){
    return x>y;
}
int main()
{
    int n,m,k;

    while(scanf("%d%d%d",&n,&m,&k)==3)
    {
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }

        sort(a,a+n,cmp);

        int rem=m;
        int cnt=0;

        if(rem>k)
        {
            rem = rem-(k-1);

            for(int i=0; i<n; i++)
            {
                if(rem<=a[i]){
                    cnt++;
                    rem=0;
                    break;
                }
                else{
                    rem = rem-(a[i]-1);
                    cnt++;
                }
            }
        }
        else{
            rem=0;
        }

        if(rem==0){
            printf("%d\n",cnt);
        }
        else{
            printf("-1\n");
        }

    }

    return 0;
}

