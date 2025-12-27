#include<bits/stdc++.h>
using namespace std;
#define ll long long
int r,d,n,rr,dd,rd,rrdd;
int main()
{
    double eps = 0.00000001;
    scanf("%d%d",&r,&d);
    if(r<=d)swap(r,d);

    //rr=r*r;
    //dd=d*d;
    rd=r-d;
    //rdrd=rd*rd;

    scanf("%d",&n);

    int cnt=0;

    for(int i=1; i<=n; i++)
    {
        int xi,yi,ri;
        scanf("%d%d%d",&xi,&yi,&ri);

        int ds = (xi*xi)+(yi*yi);
        double ss = sqrt((double)ds);
        double pp = ss+(double)ri;
        double qq = ss-(double)ri;

        if((double)rd <= (qq+eps))
        {
            if(pp<=((double)r+eps))
            {
                cnt++;
            }
        }
    }

    printf("%d\n",cnt);

    return 0;
}
