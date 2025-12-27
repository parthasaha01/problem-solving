#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
map<char,string>mp;
vector<int>divisor;
vector< pair<int,int> > v[2];
string s[5205];
int n, a[5201][5201], b[5201][5201];
int fun(int x){
    memset(b,-1,sizeof(b));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int ii = (i/x) + ((i%x) != 0);
            int jj = (j/x) + ((j%x) != 0);
            if(b[ii][jj]==-1){
                b[ii][jj] = a[i][j];
            }else{
                if(b[ii][jj] != a[i][j]) return 0;
                b[ii][jj] = a[i][j];
            }
        }
    }

    return 1;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);

//    int maxx = 0;
//    for(int k=1; k<=5200; k++){
//        int cnt = 0;
//        for(int i=1; i<=k; i++){
//            if(k%i==0){
//                cnt++;
//            }
//        }
//        maxx = max(maxx,cnt);
//    }
//    cout<<maxx<<endl;

    mp['0'] = "0000"; mp['1'] = "0001";
    mp['2'] = "0010"; mp['3'] = "0011";
    mp['4'] = "0100"; mp['5'] = "0101";
    mp['6'] = "0110"; mp['7'] = "0111";
    mp['8'] = "1000"; mp['9'] = "1001";
    mp['A'] = "1010"; mp['B'] = "1011";
    mp['C'] = "1100"; mp['D'] = "1101";
    mp['E'] = "1110"; mp['F'] = "1111";

    cin>>n;
    for(int i=0; i<n; i++){
        string c; cin>>c;
        for(int j=0; j<c.size(); j++){
            s[i] += mp[c[j]];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
//            if(s[i][j]=='0'){
//                v[0].push_back(make_pair(i,j));
//            }else{
//                v[1].push_back(make_pair(i,j));
//            }
            a[i+1][j+1] = s[i][j]-'0';
            //cout<<a[i][j];
        }
       // cout<<endl;
    }

    for(int i=1; i<=n; i++){
        if(n%i==0){
            divisor.push_back(i);
        }
    }

    reverse(divisor.begin(), divisor.end());

    int ans=1;
    for(int i=0; i<divisor.size(); i++){
        int x = divisor[i];
        if(fun(x)==1){
            ans = x;
            break;
        }
    }

    cout<<ans<<endl;

    return 0;
}

