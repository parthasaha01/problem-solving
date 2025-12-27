#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; scanf("%d",&n);

    if(n==2)
    {
        printf("-1\n");
        printf("1 2\n");
       // return 0;
    }
    else if(n==3)
    {
        printf("-1\n");
        printf("1 2\n");
        printf("1 3\n");
        //return 0;
    }
    else if(n==4)
    {
        printf("-1\n");
        printf("1 2\n");
        printf("1 3\n");
        printf("1 4\n");
       // return 0;
    }
    else if(n==5)
    {
        printf("-1\n");
        printf("1 2\n");
        printf("1 3\n");
        printf("1 4\n");
        printf("1 5\n");
       // return 0;
    }
    else
    {
        printf("1 2\n");
        printf("1 3\n");
        printf("1 4\n");
        for(int i=5; i<=n; i++)
        {
            printf("2 %d\n",i);
        }
        for(int i=2; i<=n; i++)
        {
            printf("1 %d\n",i);
        }
    }

   // main();
    return 0;
}
