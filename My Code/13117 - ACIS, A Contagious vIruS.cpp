#include<bits/stdc++.h>
using namespace std;
struct dt
{
    double x,y;
}p[25];
int main()
{
    string s;
    while(cin>>s)
    {
        if(s=="*"){
            break;
        }

        int n;

        if(s.size()==1){
            n=s[0]-'0';
        }
        else{
            n=((s[0]-'0')*10)+(s[1]-'0');
        }

        double cx,cy;
        scanf("%lf%lf",&cx,&cy);

        for(int i=0; i<n; i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        p[n].x=p[0].x;
        p[n].y=p[0].y;

        double minn=99999999999.0;

        for(int i=0; i<n; i++)
        {
            double ax,ay,bx,by;
            ax=p[i].x;
            ay=p[i].y;
            bx=p[i+1].x;
            by=p[i+1].y;

            double mx,my;

            for(int k=1; k<=200; k++)
            {
                mx=(ax+bx)/2.0;
                my=(ay+by)/2.0;

                double a,b,c;

                a=((cx-mx)*(cx-mx))+((cy-my)*(cy-my));
                b=((ax-mx)*(ax-mx))+((ay-my)*(ay-my));
                c=((cx-ax)*(cx-ax))+((cy-ay)*(cy-ay));

                if(c==a+b){
                    break;
                }
                else if(c<a+b){
                    bx=mx;
                    by=my;
                }
                else{
                    ax=mx;
                    ay=my;
                }
            }

            double dis;
            dis=sqrt(((cx-mx)*(cx-mx))+((cy-my)*(cy-my)));

            if(dis<minn){
                minn=dis;
            }
        }

        printf("%.3lf\n",minn);
    }

    return 0;
}

