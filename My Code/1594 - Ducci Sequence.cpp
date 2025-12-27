#include<bits/stdc++.h>
using namespace std;
int a[25];
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        int n;
        scanf("%d",&n);

        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }

        bool loop=true;

        for(int k=0; k<=1000; k++)
        {
            int sum=0;
            a[n]=a[0];

            for(int i=0; i<n; i++)
            {
                a[i] = abs(a[i]-a[i+1]);
                sum+=a[i];
            }

            if(sum==0){
                loop=false;
                break;
            }
        }

        if(loop){
            printf("LOOP\n");
        }
        else{
            printf("ZERO\n");
        }

    }

    return 0;
}
