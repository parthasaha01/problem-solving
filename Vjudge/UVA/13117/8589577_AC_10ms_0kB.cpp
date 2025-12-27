#include<bits/stdc++.h>
using namespace std;
int main()
{
    string nn;
    double ox,oy,oa,ob,ab,om,am,mx,my,ax,ay,bx,by,ans;
    double px[25],py[25];

    while(cin>>nn)
    {
        if(nn=="*")break;

        int n=0;
        for(int i=0; i<nn.size(); i++)
            n = (n*10)+(nn[i]-'0');

        scanf("%lf%lf",&ox,&oy);

        for(int i=0; i<n; i++)
            scanf("%lf%lf",&px[i],&py[i]);
        px[n]=px[0]; py[n]=py[0];

        double ans=1000.0;

        for(int i=0; i<n; i++)
        {
            double ax,ay,bx,by;
            ax=px[i], ay=py[i], bx=px[i+1], by=py[i+1];

            for(int k=1; k<=200; k++)
            {
                oa = (ox-ax)*(ox-ax) + (oy-ay)*(oy-ay);
                ob = (ox-bx)*(ox-bx) + (oy-by)*(oy-by);
                //ab = (ax-bx)*(ax-bx) + (ay-by)*(ay-by);

                mx = (ax+bx)/2;
                my = (ay+by)/2;

                am = (ax-mx)*(ax-mx) + (ay-my)*(ay-my);
                om = sqrt(abs(oa-am));

                if(oa>ob){
                    ax = mx;
                    ay = my;
                }
                else{
                    bx = mx;
                    by = my;
                }
            }

            ans = min(om,ans);
        }
        printf("%.3lf\n",ans);
    }

    return 0;
}
