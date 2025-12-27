#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;

    while(cin>>n)
    {

        printf("%d\n",n/2);
        for(int i=1; i<n/2; i++)
        {

            printf("2 ");

        }

        if(n%2==0)
            printf("2\n");
        else
            printf("3\n");

    }

    return 0;
}
