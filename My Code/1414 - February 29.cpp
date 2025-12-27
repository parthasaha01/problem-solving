#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    string s1,s2;
    char ch;
    int d1,d2,y1,y2;

    for(int kase=1; kase<=t; kase++)
    {
        cin >> s1 >> d1 >> ch >> y1;
        cin >> s2 >> d2 >> ch >> y2;

        //cout << s1 << " " << d1 << " " << ch << " " << y1 << endl;
        //cout << s2 << " " << d2 << " " << ch << " " << y2 << endl;ii

        if(!(s1=="January" || s1=="February"))y1++;
        if((s2=="January" || (s2=="February")&&d2<29))y2--;
        y1--;

        //printf("y1=%d y2=%d\n",y1,y2);

        int lb = (y1/4) - (y1/100) + (y1/400);
        int ub = (y2/4) - (y2/100) + (y2/400);
        int ans = ub-lb;

        //printf("lb=%d ub=%d\n",lb,ub);

        if(ans<0)ans=0;
        printf("Case %d: %d\n",kase,ans);
    }
    return 0;
}
