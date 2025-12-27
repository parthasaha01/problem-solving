#include<bits/stdc++.h>
using namespace std;
#define vvi vector< vector<int> >
vvi a,b;
int n;
void isValid(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if((b[i][j]!=a[i][j]) || (b[i][j] != a[j][i])) return 0;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tt; cin>>tt;
    while(tt--){
        cin>>n;
        for(int i=0; i<n; i++){
            vector<int> temp;
            for(int j=0; j<n; j++){
                a.push_back(temp);
            }
        }

        for(int i=0; i<n; i++){
            vector<int> temp;
            for(int j=0; j<n; j++){
                b.push_back(temp);
            }
        }

        int flag = isValid();
        if(flag==0){
            cout<<"No"<<endl;
        }else{

        }
    }
    return 0;
}
