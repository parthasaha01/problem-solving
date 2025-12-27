#include<bits/stdc++.h>
using namespace std;
long int a[105];
int main()
{
    long int n,b,e,flag;

    while(scanf("%ld",&n)==1)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%ld",&a[i]);
        }
        while(1)
        {
            flag=0;
            for(int i=1; i<n; i++)
            {
                if(a[i]>a[i+1])
                {
                    swap(a[i],a[i+1]);

                    if(flag==0)
                    {
                        b=i;
                    }
                    e=i+1;
                    i++;
                    flag=1;
                }
                else
                {
                    if(flag!=0)
                    {
                        e=i-1;
                        break;
                    }
                }
            }

            if(flag==0)
            {
                break;
            }
            printf("%ld %ld\n",b,e);
        }
    }

    return 0;
}
