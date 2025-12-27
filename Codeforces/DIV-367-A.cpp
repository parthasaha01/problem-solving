#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b;

    while(cin >> a >> b)
    {
        int n;
        cin>> n;

        double minn = 9999999999.0;
        for(int i=0; i<n; i++)
        {
            double x,y,v;
            cin >> x >> y >> v;

            double d = sqrt(((a-x)*(a-x))+((b-y)*(b-y)));
            double t = d/v;

            if(t<minn){
                minn=t;
            }

        }

        printf("%.10lf\n",minn);
    }

    return 0;
}
