#include<bits/stdc++.h>
using namespace std;
int a[55];
int gcd(int x, int y){
    if(x==0){
        return y;
    }
    gcd(y%x,x);
}
int main()
{
    long int n;
    double hor,res;

    while(scanf("%ld",&n) && n)
    {
        hor = ((n*(n+1))/2)-n;

        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }
        int cnt=0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int flag = gcd(a[i],a[j]);
                if(flag==1){
                    cnt++;
                }
            }
        }

        if(cnt==0)
        {
            printf("No estimate for this data set.\n");
        }
        else{
            hor = (6*hor)/(double)cnt;
            res = sqrt(hor);
            printf("%.6lf\n",res);
        }

    }

    return 0;
}
