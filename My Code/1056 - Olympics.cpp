#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    double len,wid,a,b,high,low,mid,peri,L,W,arc,ang,val,r,d;
    scanf("%d",&T);

    for(int test=1; test<=T; test++)
    {

        scanf("%lf : %lf",&a,&b);

        high=400;
        low=0;

        while(high-low>0.000000001)
        {
            mid=(high+low)/2.0;
            L=mid;
            W=(b*L)/a;
            d=sqrt((L*L)+(W*W));
            r=d/2;
            val=((2*r*r)-(W*W))/(2*r*r);
            ang=acos(val);
            arc=r*ang;
            peri=2*(L+arc);

            if(peri>400.0){
                high=mid;
            }
            else if(peri<400){
                low=mid;
            }
            else{
                break;
            }
        }
        printf("Case %d: %.8lf %.8lf\n",test,L,W);
    }

    return 0;
}
