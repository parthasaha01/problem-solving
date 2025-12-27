#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        double ox,oy,ax,ay,bx,by;
        scanf("%lf%lf%lf%lf%lf%lf",&ox,&oy,&ax,&ay,&bx,&by);

        double r=sqrt((ax-ox)*(ax-ox)+(ay-oy)*(ay-oy)); // r=oa=ob
        double ab=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));

        double angle = acos((r*r+r*r-ab*ab)/(2.0*r*r));
        double arc = r*angle;

        printf("Case %d: %lf\n",kase,arc);
    }

    return 0;
}
