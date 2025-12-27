#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;

    while(cin >> n >> k)
    {
        for(int i=1; i<n-k; i++)
        {
            printf("%d ",i);
        }

        for(int i=n; i>=n-k; i--)
        {
            printf("%d",i);
            if(i>n-k)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
