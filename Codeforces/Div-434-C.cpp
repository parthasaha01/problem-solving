#include<bits/stdc++.h>
using namespace std;
vector<string>vv;
int isvowel(char ch)
{
    if(ch=='a'||ch=='e' || ch=='i'||ch=='o' || ch=='u'){
        return 1;
    }

    return 0;
}
int main()
{
    string s,w;
    cin>>s;
    int cs=0;
    for(int i=0; i<s.size(); i++)
    {
        if(isvowel(s[i])==0)
        {
            int flag = 0;
            if(cs>=2){
                if(!(s[i]==s[i-1] && s[i]==s[i-2])){
                    vv.push_back(w);
                    w="";
                    cs=0;
                }
            }

            cs++;
            w+=s[i];
        }
        else{
            w+=s[i];
            cs=0;
        }
    }

    int sw=w.size();

    if(sw>0){
        vv.push_back(w);
    }

    int sz=vv.size();

    for(int i=0; i<sz; i++)
    {
        if(i==sz-1)cout << vv[i] << endl;
        else cout << vv[i] << " ";
    }

    vv.clear();
    //main();
    return 0;
}
