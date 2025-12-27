#include<bits/stdc++.h>
using namespace std;
vector<string>v;
int main()
{
    string s;
    int n;

    while(cin >> n >> s)
    {
        int sz=s.size();

        for(int i=0; i<=sz-n; i++)
        {
            string s1 = s.substr(i,n);
            //cout << s1 << endl;
            v.push_back(s1);
        }
        //cout << endl;

        sort(v.begin(),v.end());

        int maxx=0;
        string res;
        int vz=v.size();
        int cnt=1;
        for(int i=0; i<vz-1; i++)
        {
            //cout << v[i] << endl;

            if(v[i]!=v[i+1])
            {
                if(cnt>maxx){
                    maxx=cnt;
                    res=v[i];
                    //cout << res << " " << maxx << endl;
                }
                cnt=1;
            }
            else{
                cnt++;
            }
        }
        //cout << endl;

        cout << res << endl;

        v.clear();
    }

    return 0;
}
