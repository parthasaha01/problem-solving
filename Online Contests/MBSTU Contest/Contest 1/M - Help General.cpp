#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,r,res,c1,r1;

    while(cin >> c >> r)
    {
        if(c==1 || r==1)
        {
            res = max(c,r);
        }
        else
        {
            if(c%3==0){
                c1=c/3;
            }
            else{
                c1=(c/3)+1;
            }
            if(r%3==0){
                r1=r/3;
            }
            else{
                r1=(r/3)+1;
            }

            c1 *= r;
            r1 *= c;

            res = max(c1,r1);
        }

        cout << res << endl;
    }

    return 0;
}
