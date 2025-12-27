#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,r,b,c,d;
int main()
{
    while(cin>>a>>b>>c)
    {
        if(a%b==0)
        {
            if(c==0){
                printf("1\n");
            }
            else{
                printf("-1\n");
            }

            //continue;
        }
        else
        {
            r = a;
            a = a%b;
            bool flag = false;
            ll p;
            ll ans = -1;
            for(int k=1; k<=100000; k++)
            {
                a = a*10;
                d = a/b;
                a = a%b;
                if(d==c)
                {
                    ans = k;
                    flag = true;
                    break;
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}
