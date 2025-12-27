#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string ss;
    string p = "ACGT";
    while(cin>>n)
    {
        cin>>ss;
        if(n%4!=0){
            printf("===\n"); continue;
        }

        map<char,int>mp;
        for(char i='A'; i<='Z'; i++){
            mp[i] = 0;
        }

        for(int i=0; i<ss.size(); i++) mp[ss[i]]++;
        int cnt = n/4;
        if(mp['A']>cnt || mp['C']>cnt || mp['G']>cnt || mp['T']>cnt){
            printf("===\n"); continue;
        }
        if(mp['?']==0){
            cout << ss << endl; continue;
        }
        string tmp;
        for(int i=0; i<4; i++){
            while(mp[p[i]]<cnt){
                tmp+=p[i];
                mp[p[i]]++;
            }
        }

        for(int i=0,j=0; i<n; i++){
            if(ss[i]=='?'){
                ss[i] = tmp[j++];
            }
        }
        cout << ss << endl;
    }
    return 0;
}
