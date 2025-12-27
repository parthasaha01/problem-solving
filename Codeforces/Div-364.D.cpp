#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n,l,v1,v2,k;
    //int n,l,v1,v2,k;

    while(cin>>n>>l>>v1>>v2>>k)
    {
        int nt;
        if((n/k)==(int)(n/k)){
            nt = n/k;
        }
        else{
            nt = (n/k)+1;
        }

        double time=0.0;
        double pos=0.0;
        double rem=n;
        double t1,t;
        t=0.0;

        for(int i=1; i<=nt && pos<l; i++)
        {
            t1 = (l-pos)/v2;
            t+=t1;
            rem=n-k;
            pos=v1*t;
            if(rem<=0)
                break;
        }

        printf("%.10lf\n",t);
    }

    return 0;
}
