#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100005
int a[105];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        int status=-1;

        if(n==1)
        {
            if(a[n]==15){
                printf("DOWN\n");
            }
            else if(a[n]==0){
                printf("UP\n");
            }
            else{
                printf("-1\n");
            }
        }
        else
        {
            int x=a[n-1];
            int y=a[n];

            if(x==1&&y==0){
                printf("UP\n");
            }
            else if(x==14&&y==15){
                printf("DOWN\n");
            }
            else if(x<y){
                printf("UP\n");
            }
            else if(x>y){
                printf("DOWN\n");
            }
        }
    }

    return 0;
}
