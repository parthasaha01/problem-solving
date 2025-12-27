
#include<bits/stdc++.h>
using namespace std;
const double eps = 0.0000001;
double triangleArea(double ax,double ay,double bx,double by,double cx,double cy)
{
    double a,b,c,s,area;
    a = sqrt( ((bx-cx)*(bx-cx)) + ((by-cy)*(by-cy)) );
    b = sqrt( ((ax-cx)*(ax-cx)) + ((ay-cy)*(ay-cy)) );
    c = sqrt( ((bx-ax)*(bx-ax)) + ((by-ay)*(by-ay)) );
    s = (a+b+c)/2.0;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        double L,x,y,u,v;
        scanf("%lf %lf %lf",&L,&x,&y);
        //printf("%lf %lf %lf\n",L,x,y);

        double total_area = triangleArea(0.0,0.0,0.0,L,L,0.0);
        //double half_area = total_area/2.0;

        if(fabs(x-0.0)<=eps && fabs(y-0.0)<=eps)
        {
            u = L/2.0;
            v = L/2.0;
            //cout << u << " " << v << endl;
            printf("%.6lf %.6lf\n",u,v);
            continue;
        }
        if(fabs(x-0.0)<=eps && fabs(L-y)<=eps)
        {
//            double u1,u2,v1,v2,a1,a2,d1,d2;
//
//            double px,py,qx,qy,mx,my;
//            px = 0.0; py = 0.0;
//            qx = L; qy = 0.0;
//
//            for(int i=1; i<=1000; i++)
//            {
//                 mx = (px+qx)/2.0;
//                 my = (py+qy)/2.0;
//
//                 double area = 2.0*triangleArea(0.0,0.0,x,y,mx,my);
//                 if(area>total_area){
//                    qx = mx; qy = my;
//                 }
//                 else{
//                    px = mx; py = my;
//                 }
//            }
//            u = mx;
//            v = my;
            u = L/2.0;
            v = 0.0;

           // cout << u << " " << v << endl;
            printf("%.6lf %.6lf\n",u,v);
            continue;

        }

        if(fabs(y-0.0)<=eps && fabs(L-x)<=eps)
        {
//            double u1,u2,v1,v2,a1,a2,d1,d2;
//
//            double px,py,qx,qy,mx,my;
//            px = 0.0; py = L;
//            qx = 0.0; qy = 0.0;
//
//            for(int i=1; i<=1000; i++)
//            {
//                 mx = (px+qx)/2.0;
//                 my = (py+qy)/2.0;
//
//                 double area = 2.0*triangleArea(0.0,0.0,x,y,mx,my);
//                 if(area>total_area){
//                    px = mx; py = my;
//                 }
//                 else{
//                    qx = mx; qy = my;
//                 }
//            }
//            u = mx;
//            v = my;
            u = 0.0;
            v = L/2.0;
            //cout << u << " " << v << endl;
            printf("%.6lf %.6lf\n",u,v);
            continue;
        }

        if(fabs(x-0.0)<=eps)
        {
            double u1,u2,v1,v2,a1,a2,d1,d2;

            double px,py,qx,qy,mx,my;
            px = 0.0; py = 0.0;
            qx = L; qy = 0.0;

            for(int i=1; i<=1000; i++)
            {
                 mx = (px+qx)/2.0;
                 my = (py+qy)/2.0;

                 double area = 2.0*triangleArea(0.0,0.0,x,y,mx,my);
                 if(area>total_area){
                    qx = mx; qy = my;
                 }
                 else{
                    px = mx; py = my;
                 }
            }
            u1 = mx;
            v1 = my;
            a1 = 2.0*triangleArea(0.0,0.0,x,y,u1,v1);
            d1 = fabs(total_area-a1);

            //double px,py,qx,qy,mx,my;
            px = 0.0; py = L;
            qx = L; qy = 0.0;
            for(int i=1; i<=1000; i++)
            {
                 mx = (px+qx)/2.0;
                 my = (py+qy)/2.0;

                 double area = 2.0*triangleArea(0.0,L,x,y,mx,my);
                 if(area>total_area){
                    qx = mx; qy = my;
                 }
                 else{
                    px = mx; py = my;
                 }
            }
            u2 = mx;
            v2 = my;
            a2 = 2.0*triangleArea(0.0,L,x,y,u2,v2);
            d2 = fabs(total_area-a2);

            if(d1<d2){
                u = u1; v=v1;
            }
            else{
                u = u2; v = v2;
            }

            //cout << u << " " << v << endl;
            printf("%.6lf %.6lf\n",u,v);
            continue;
        }
        else if(fabs(y-0.0)<=eps)
        {
            double u1,u2,v1,v2,a1,a2,d1,d2;

            double px,py,qx,qy,mx,my;
            px = 0.0; py = L;
            qx = 0.0; qy = 0.0;

            for(int i=1; i<=1000; i++)
            {
                 mx = (px+qx)/2.0;
                 my = (py+qy)/2.0;

                 double area = 2.0*triangleArea(0.0,0.0,x,y,mx,my);
                 if(area>total_area){
                    px = mx; py = my;
                 }
                 else{
                    qx = mx; qy = my;
                 }
            }
            u1 = mx;
            v1 = my;
            a1 = 2.0*triangleArea(0.0,0.0,x,y,u1,v1);
            d1 = fabs(total_area-a1);
            //double px,py,qx,qy,mx,my;
            px = 0.0; py = L;
            qx = L; qy = 0.0;
            for(int i=1; i<=1000; i++)
            {
                 mx = (px+qx)/2.0;
                 my = (py+qy)/2.0;

                 double area = 2.0*triangleArea(L,0.0,x,y,mx,my);
                 if(area>total_area){
                    px = mx; py = my;
                 }
                 else{
                    qx = mx; qy = my;
                 }
            }
            u2 = mx;
            v2 = my;
            a2 = 2.0*triangleArea(L,0.0,x,y,u2,v2);
            d2 = fabs(total_area-a2);

            if(d1<d2){
                u = u1; v=v1;
            }
            else{
                u = u2; v = v2;
            }

            //cout << u << " " << v << endl;
            printf("%.6lf %.6lf\n",u,v);
            continue;
        }
        else
        {
            double u1,u2,v1,v2,a1,a2,d1,d2;

            double px,py,qx,qy,mx,my;
            px = 0.0; py = L;
            qx = 0.0; qy = 0.0;

            for(int i=1; i<=1000; i++)
            {
                 mx = (px+qx)/2.0;
                 my = (py+qy)/2.0;

                 double area = 2.0*triangleArea(0.0,L,x,y,mx,my);
                 if(area>total_area){
                    qx = mx; qy = my;
                 }
                 else{
                    px = mx; py = my;
                 }
            }
            u1 = mx;
            v1 = my;
            a1 = 2.0*triangleArea(0.0,0.0,x,y,u1,v1);
            d1 = fabs(total_area-a1);

            //double px,py,qx,qy,mx,my;
            px = 0.0; py = 0.0;
            qx = L; qy = 0.0;
            for(int i=1; i<=1000; i++)
            {
                 mx = (px+qx)/2.0;
                 my = (py+qy)/2.0;

                 double area = 2.0*triangleArea(L,0.0,x,y,mx,my);
                 if(area>total_area){
                    px = mx; py = my;
                 }
                 else{
                    qx = mx; qy = my;
                 }
            }
            u2 = mx;
            v2 = my;
            a2 = 2.0*triangleArea(L,0.0,x,y,u2,v2);
            d2 = fabs(total_area-a2);

            if(d1<d2){
                u = u1; v=v1;
            }
            else{
                u = u2; v = v2;
            }

            //cout << u << " " << v << endl;
            printf("%.6lf %.6lf\n",u,v);
            continue;
        }
    }
    return 0;
}

