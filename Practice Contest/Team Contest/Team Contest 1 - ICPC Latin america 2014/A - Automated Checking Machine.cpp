#include<bits/stdc++.h>
using namespace std;
int a[15],b[15];
int main()
{
    while(scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4])==5)
    {
        scanf("%d %d %d %d %d",&b[0],&b[1],&b[2],&b[3],&b[4]);

        int flag = 1;

        for(int i=0; i<5; i++)
        {
            if(a[i]==b[i]){
                flag= 0;
                break;
            }
        }

        if(flag){
            printf("Y\n");
        }
        else{
            printf("N\n");
        }
    }

    return 0;
}
