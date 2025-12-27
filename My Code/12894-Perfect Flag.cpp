#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        double x0,y0,x1,y1,cx,cy,r;
        cin>>x0>>y0>>x1>>y1>>cx>>cy>>r;

        double l=(x1-x0);
        double w=(y1-y0);
        double mx=0.45*l+x0;
        double my=0.50*w+y0;

        if((l*6.0==w*10.0)&&(r*5.0==l)&&(mx==cx&&my==cy))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
