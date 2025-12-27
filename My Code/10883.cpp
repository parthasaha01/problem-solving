#include<bits/stdc++.h>
using namespace std;
double ar[50005],br[50005];
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        int n;
        scanf("%d",&n);

        for(int i=0; i<n; i++){
            scanf("%lf",&br[i]);
            //br[i]=ar[i];
        }

        for(int i=0; i<n-1; i++)
        {
            int k=n-i-1;
            for(int j=0; j<k; j++){
                br[j]=(br[j]+br[j+1])/2.0;
                //printf("%.3lf ",br[j]);
            }
            //printf("\n");
        }

        /*double avg=0.0,av=0.0;
        avg +=ar[0];
        avg +=ar[n-1];
        for(int i=1; i<n-1; i++){
            av += ar[i];
        }
        av = (n-1)*av;
        avg += av;

        for(int i=2; i<n; i++){
            avg = avg/2.0;
        }*/

        printf("Case #%d: %.3lf\n",kase,br[0]);
    }

    return 0;
}
