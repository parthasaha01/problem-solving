#include<stdio.h>
int main()
{
    int H,M;
    double H1,M1,T,angle;
    char ch;

    while(scanf("%d",&H)==1)
    {
        scanf("%c",&ch);
        scanf("%d",&M);

        if(H==0.0 && M==0.0)
        {
            break;
        }

        M1=M/5.0;
        H1=H-M1;
        T=H1*30.0;
        angle=T+(M/2.0);
        if(angle<0)
        {
            angle=-angle;
        }

        if(angle>180.0)
        {
            angle=360.0-angle;
        }

        printf("%.3lf\n",angle);
    }

    return 0;
}
