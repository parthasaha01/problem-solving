#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s; cin>>s;
    int maxx = 0;
    for(int i=0; i<s.size(); i++){
        string p;
        for(int j=i; j<s.size(); j++){
            p += s[j];
            string q = p;
            reverse(q.begin(),q.end());
            if(p!=q){
                maxx = max(maxx,(int)p.size());
            }
        }
    }

    cout << maxx << endl;

    //main();

    return 0;
}
