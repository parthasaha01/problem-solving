#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        int start=1;

        for(int i=0; i<n; i++)
        {
            if(a[i]!=1)
            {
                if(a[i]%2==1)
                {
                    if(start==1)
                    {
                        printf("2\n");
                        start=1;
                    }
                    else
                    {
                        printf("1\n");
                        start=2;
                    }
                }
                else
                {
                    if(start==1)
                    {
                        printf("1\n");
                        start=2;
                    }
                    else
                    {
                        printf("2\n");
                        start=1;
                    }
                }
            }
            else
            {
                if(start==1)
                {
                    printf("2\n");
                }
                else{
                    printf("1\n");
                }
            }
        }
    }

    return 0;
}
