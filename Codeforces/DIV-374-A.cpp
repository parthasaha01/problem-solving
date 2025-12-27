#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
    string s;
    int n;
    while(cin>>n)
    {
        cin >> s;
        v.clear();

        int sz=s.size();
        bool start=false;
        int cnt=0;
        for(int i=0; i<sz; i++)
        {
            if(s[i]=='B'){
                cnt++;
            }
            else
            {
                if(cnt!=0)
                {
                    v.push_back(cnt);
                    cnt=0;
                }
            }
        }

        if(cnt!=0){
            v.push_back(cnt);
            cnt=0;
        }

        cout << v.size() << endl;
        for(int i=0; i<v.size(); i++)
        {
            if(i==v.size()-1){
                cout << v[i] << endl;
            }
            else{
                cout << v[i] << " ";
            }
        }
    }

    return 0;
}
