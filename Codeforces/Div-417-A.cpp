#include<bits/stdc++.h>
using namespace std;
int a[5][5];
bool fun()
{
    if(a[1][4]==1)
    {
        if(a[1][1] || a[1][2] || a[1][3] || a[2][1] || a[3][2] || a[4][3]){
            return true;
        }
    }

    if(a[2][4])
    {
        if(a[1][3] || a[2][1] || a[2][2] || a[2][3] || a[3][1] || a[4][2]){
            return true;
        }
    }
    if(a[3][4])
    {
        if(a[1][2] || a[2][3] || a[3][1] || a[3][2] || a[3][3] || a[4][1]){
            return true;
        }
    }
    if(a[4][4]){
        if(a[1][1] || a[2][2] || a[3][3] || a[4][1] || a[4][2] || a[4][3]){
            return true;
        }
    }

    return false;
}
int main()
{
    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=4; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    bool flag = fun();

    if(flag){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

    return 0;
}
