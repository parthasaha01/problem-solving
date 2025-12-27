#include<bits/stdc++.h>
using namespace std;
string s[105];
struct dt
{
    string p;
    int v;
}x[105];
bool cmp(dt x1,dt x2){
    return x1.v>x2.v;
}

int main()
{
    int t;
    cin >> t;

    for(int kase=1; kase<=t; kase++)
    {
        int n,a,b,c;
        cin>>n;

        for(int i=0; i<n; i++){
            cin >> s[i] >> a >> b >> c;
            x[i].p=s[i];
            x[i].v=(a*b*c);
        }

        sort(x,x+n,cmp);

        if(x[0].v==x[1].v){
            cout << "Case " << kase << ": no thief" << endl;
        }
        else{
            cout << "Case " << kase << ": " << x[0].p << " took chocolate from " << x[n-1].p << endl;
        }
    }

    return 0;
}
