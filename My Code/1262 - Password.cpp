#include<bits/stdc++.h>
using namespace std;
string a[6],b[6];
int w[7];
int main()
{
    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++)
    {
        int n; cin>>n;

        for(int i=0; i<6; i++)cin>>a[i];
        for(int i=0; i<6; i++)cin>>b[i];

        vector<char>v[7];

        for(int j=0; j<5; j++){
            for(char c='A'; c<='Z'; c++){
                int f = 0;
                for(int i=0; i<6; i++){
                    if(a[i][j]==c){
                        f++; break;
                    }
                }
                if(f==0)continue;
                for(int i=0; i<6; i++){
                    if(b[i][j]==c){
                        f++; break;
                    }
                }
                if(f==1)continue;
                v[j].push_back(c);
            }
        }

        v[5].push_back('A');

        w[5]=1;
        for(int i=4; i>=0; i--)w[i] = w[i+1]*(int)v[i].size();

        if(n>w[0]){
            printf("NO\n");
            continue;
        }

        string ans;
        for(int j=0; j<5; j++){
            for(int i=0; i<v[j].size(); i++){
                if(n<=w[j+1]){
                    ans += v[j][i];
                    break;
                }
                else{
                    n -= w[j+1];
                }
            }
        }

        cout << ans <<endl;
    }
    return 0;
}
