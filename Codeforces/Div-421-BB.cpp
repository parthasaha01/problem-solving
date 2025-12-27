#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    while(scanf("%d%d",&n,&a)==2)
    {
        double dn,da;
        dn = (double)n;
        da = (double)a;

        double mn = 200.0;

        double tot = (dn-2.0)*180.0;
        double each = tot/dn;

        double eap = each/(dn-2.0);

        int x,y,z,mx=1,my=2,mz=3;
        x = 1;
        y = 2;
        int i=1;
        for(int z=n; z>=3; z--)
        {
            //int df,ang;
//            ang = each;
//            df = abs(y-x)-1;
//            ang -= (df*eap);
//
//            df = abs(n-z);
//            ang -= (df*eap);
//
            //double cnt;
//            if(da>=ang)
//            {
//                cnt = da-ang;
//            }
//            else
//            {
//                cnt = ang-da;
//
//            }
//
//            if(cnt<mn)
//            {
//                mn = cnt;
//                mx = z;
//                my = x;
//                mz = y;
//
//            }

//            ang = each;
//            df = abs(z-y)-1;
//            ang -= (df*eap);
//
//            df = abs(y-x)-1;
//            ang -= (df*eap);

            double ang = eap*i;
            double cnt;
            if(da>=ang)
            {
                cnt = da-ang;
            }
            else
            {
                cnt = ang-da;

            }

            if(cnt<mn)
            {
                mn = cnt;
                mx = x;
                my = y;
                mz = z;

            }

//            ang = each;
//            df = abs(z-y)-1;
//            ang -= (df*eap);
//
//            df = abs(n-z);
//            ang -= (df*eap);
//
//            if(da>=ang)
//            {
//                cnt = da-ang;
//            }
//            else
//            {
//                cnt = ang-da;
//
//            }
//
//            if(cnt<mn)
//            {
//                mn = cnt;
//                mx = y;
//                my = z;
//                mz = x;
//
//            }

        }

        printf("%d %d %d\n",mx,my,mz);

    }

    return 0;
}

