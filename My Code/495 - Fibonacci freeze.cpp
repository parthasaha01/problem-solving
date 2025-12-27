#include<bits/stdc++.h>
using namespace std;
string ss[5005];
void precalculate()
{
    ss[0] = "0";
    ss[1] = "1";

    for(int i=2; i<=5001; i++)
    {
        string x,y,z;
        x = ss[i-1];
        y = ss[i-2];

        reverse(x.begin(),x.end());
        reverse(y.begin(),y.end());

        int a,b,s,ci=0,k;
        for(k=0; k<y.size(); k++)
        {
            a = x[k]-'0';
            b = y[k]-'0';
            s = a+b+ci;
            ci = s/10;
            s = s%10;
            z += s+'0';
        }

        for( ; k<x.size(); k++)
        {
            a = x[k]-'0';
            s = a+ci;
            ci = s/10;
            s = s%10;
            z += s+'0';
        }

        if(ci>0)z += ci+'0';

        reverse(z.begin(),z.end());

        ss[i] = z;
    }
}
int main()
{
    precalculate();

    int n;
    while(scanf("%d",&n)==1)
    {
        cout << "The Fibonacci number for " << n <<" is " << ss[n] << endl;
        //cout << ss[n].size() << endl;
    }
    return 0;
}
