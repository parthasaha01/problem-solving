#include<bits/stdc++.h>
using namespace std;
double a[105];
int main()
{
    int n,k;

    while(cin>>n>>k)
    {
        double total=0.0;

        for(int i=1; i<=n; i++){
            cin>>a[i];
            total+=a[i];
        }

        double avg;
        avg = (total/(double)n);
        double sum;
        sum = round(avg);

        if((int)sum==k){
            printf("0\n");
            continue;
        }

        //printf("%lf %lf\n",avg,sum);

        int ans = 0;
        int nn= n;
        while(true)
        {
            total+=k;
            nn++;
            ans++;
            avg = (total/(double)nn);
            sum=round(avg);
            if((int)sum==k){
                break;
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
