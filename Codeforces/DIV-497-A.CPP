#include<bits/stdc++.h>
using namespace std;
#define lll long long
#define mx 100005
string s;
int mp[30];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>s;
    int n = s.size();

    mp['a'-'a']=1;
    mp['e'-'a']=1;
    mp['i'-'a']=1;
    mp['o'-'a']=1;
    mp['u'-'a']=1;
    mp['n'-'a']=2;
    if(mp[s[n-1]-'a']==0){
        cout<<"NO"<<endl;
    }
    else{
        int f = 1;
        for(int i=0; i<n-1; i++){
            //cout<<mp[s[i]-'a']<<" "<<mp[s[i+1]-'a']<<endl;
            if(mp[s[i]-'a']==0 && mp[s[i+1]-'a']!=1){
                f=0;
                //cout<<i<<endl;
                break;
            }
        }

        if(f)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    //main();

    return 0;
}
