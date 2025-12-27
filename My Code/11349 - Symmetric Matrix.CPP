#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int T;

    scanf("%d",&T);
    int N,n;
    ll a[105][105];

    for(int test=1; test<=T; test++)
    {
        getchar();
        getchar();
        getchar();
        getchar();
        scanf("%d",&N);
        //int n;
        //printf("%d\n",n);
        int negg=0;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                scanf("%lld",&a[i][j]);

                if(a[i][j]<0){
                    negg=1;
                }
            }

        }

        if(negg)
        {
            printf("Test #%d: Non-symmetric.\n",test);
        }
        else
        {
            /*for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    printf("%d ",a[i][j]);
                }
                printf("\n");
            }*/

            int flag=1;
            int n;
            n=N-1;
            //printf("n=%d\n",n);
            for(int i=0; i<(N/2); i++)
            {
                for(int j=0; j<N; j++)
                {
                    //printf("%d ",a[i][j]);
                    //printf("%d\n",a[n-i][n-j]);
                    if(a[i][j] != a[n-i][n-j]){
                        flag=0;
                        goto label;
                        //break;
                    }
                }
                //printf("\n");
            }

            if(N&1)
            {
                for(int j=0; j<N/2; j++){
                    if(a[N/2][j] != a[N/2][n-j]){
                        flag=0;
                        goto label;
                    }
                }
            }

            label:
            if(flag)
                printf("Test #%d: Symmetric.\n",test);
            else
                printf("Test #%d: Non-symmetric.\n",test);
        }


    }

    return 0;
}
