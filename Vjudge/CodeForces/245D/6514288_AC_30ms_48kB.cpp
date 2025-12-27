#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[105][105];
int main()
{
    int n;

    while(scanf("%d",&n)==1)
    {
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d",&b[i][j]);
            }
        }

        memset(a,0,sizeof(a));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j){
                    a[i] = a[i]| b[i][j];
                }
            }
        }

        for(int i=0; i<n; i++){
            if(i<n-1){
                printf("%d ",a[i]);
            }
            else{
                printf("%d\n",a[i]);
            }
        }
    }

    return 0;
}
