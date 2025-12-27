#include<bits/stdc++.h>
using namespace std;
int F[1001];
int main()
{
    F[2]=F[3]=F[5]=F[8]=F[13]=F[21]=F[34]=F[55]=F[89]=F[144]=F[233]=F[377]=F[610]=F[987]=1;

    int n;
    while(scanf("%d",&n) && n)
    {
        if(F[n])
            printf("Roberto\n");
        else
            printf("Alicia\n");
    }

    return 0;
}


