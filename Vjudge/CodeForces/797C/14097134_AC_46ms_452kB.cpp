#include<bits/stdc++.h>
using namespace std;
int last[30];
int main()
{
    string s,u; cin>>s;
    int n = s.size();

    for(int i=0; i<n; i++){
        last[s[i]-'a'] = i;
    }
    stack<char>t;
    for(int i=0; i<n; i++){
        int id = s[i]-'a';
        int f = -1;
        for(int j=0; j<=id; j++){
            if(last[j]>i){
                f = j;
                break;
            }
        }

        if(!t.empty())
        {
            if(f==-1)
            {
                while(!t.empty() && t.top()<=id)
                {
                    u += t.top()+'a';
                    t.pop();
                }
                u += s[i];
            }
            else
            {
               while(!t.empty() && t.top()<=f)
                {
                    u += t.top()+'a';
                    t.pop();
                }
                t.push(s[i]-'a');
            }
        }
        else
        {
            if(f==-1)
            {
                u += s[i];
            }
            else
            {
                t.push(s[i]-'a');
            }
        }
    }

    while(!t.empty()){
        u += t.top()+'a';
        t.pop();
    }

    cout << u << endl;

    return 0;
}
