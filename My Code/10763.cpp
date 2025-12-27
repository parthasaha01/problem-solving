#include<bits/stdc++.h>
using namespace std;
#define maxx 10001
long int ar[maxx][maxx];
struct info{
    long int b,e;
}a[500001];
int main()
{
    long int n,x,y;

    while(scanf("%ld",&n) && n)
    {
        memset(ar,0,sizeof(ar));

        for(int i=0; i<n; i++){
            scanf("%ld %ld",&x,&y);
            a[i].b = x;
            a[i].e = y;
            ar[x][y]++;
        }
        int flag=1;
        for(int i=0; i<n; i++){
            x = a[i].b;
            y = a[i].e;
            if(ar[x][y]!=ar[y][x]){
                flag=0;
                break;
            }
        }

        if(flag){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }

    }

    return 0;
}
