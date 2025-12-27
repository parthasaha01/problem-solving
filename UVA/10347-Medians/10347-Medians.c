#include<stdio.h>
#include<math.h>
int main()
{
    double u,v,w,s,area,a,b,c;

    while(scanf("%lf %lf %lf",&u,&v,&w)==3)
    {
        if(u>v && u>w)
        {
            a=u;
            b=v;
            c=w;
        }
        else if(v>u && v>w)
        {
            a=v;
            b=u;
            c=w;
        }
        else
        {
            a=w;
            b=u;
            c=v;
        }
        if(a >=(b+c))
        {
            printf("-1.000\n");
        }
        else
        {
            s=(u+v+w)/2.0;
            s=s*(s-u)*(s-v)*(s-w);
            s=sqrt(s);
            area=(4/3.0)*s;

            printf("%.3lf\n",area);
        }
    }

    return 0;
}
