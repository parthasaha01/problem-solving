#include<bits/stdc++.h>
using namespace std;
string s[2005];
int a[2005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>s[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i][j]=='1'){
                a[j]++;
            }
        }
    }

    int flag = 0;

    for(int i=0; i<n; i++){
        int ase = 1;
        for(int j=0; j<m; j++){
            if(s[i][j]=='1'){
                if(a[j]==1){
                    ase = 0;
                    break;
                }
            }
        }

        if(ase==1){
            flag = 1;
            break;
        }
    }

    if(flag==1){
        cout << "YES" << endl;
    }
    else{
         cout << "NO" << endl;
    }

    return 0;
}

