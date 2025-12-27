#include<bits/stdc++.h>
using namespace std;
int main()
{
    string g,a;

    while(cin >> g >> a)
    {
        int sg=g.size();
        int sa=a.size();
        int cnt=0;
        for(int i=0; i<=sg-sa; )
        {
            if(g.substr(i,sa)==a){
                cnt++;
                i=i+sa;
            }
            else{
                i++;
            }
        }

        cout << cnt << endl;
    }
}
