#include<bits/stdc++.h>
using namespace std;
vector<string>vv;
vector<string>uu;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;

        vv.clear();
        uu.clear();
        int cur = 1;
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            vv.push_back(s);
        }

//        for(int i=0; i<n; i++)
//        {
//            cout << vv[i] << endl;
//        }

        for(int i=0; i<n-2; i++)
        {
            if(vv[i][0]=='F' && vv[i+1][0]=='F' && vv[i+2][0]=='T'){
                uu.push_back(vv[i]);
                uu.push_back(vv[i+1]);
                uu.push_back(vv[i+2]);
                //cout << vv[i] << " " << vv[i+1] << " " << vv[i+2] << endl;
            }
        }

        //cout << "uz=" <<

        int uz = uu.size();
        int cnt = uz/3;

        cout << cnt << endl;
        int sz = cnt*3;
        for(int i=0; i<sz;)
        {
            cout << uu[i] << " " << uu[i+1] << " " << uu[i+2] << endl;
            i++;
            i++;
            i++;
        }
    }
    return 0;
}
