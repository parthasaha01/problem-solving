#include<bits/stdc++.h>
using namespace std;
int n,k,arr[1005];
struct dd{
    string s;
    int id,len;
}a[1005];
bool cmp(dd xx, dd yy){
    return xx.len > yy.len;
}
bool possible(string x){
    bool ok = true;
    memset(arr,-1,sizeof(arr));
    for(int i=1; i<=k; i+=2){
        string s1 = a[i].s;
        string s2 = a[i+1].s;
        int id1 = a[i].id;
        int id2 = a[i+1].id;

        bool flag1 = true;
        for(int j=0; j<s1.size(); j++){
            if(x[j]!=s1[j]){
                flag1 = false;
                break;
            }
        }

        bool flag2 = true;
        for(int j=0; j<s2.size(); j++){
            if(x[j]!=s2[j]){
                flag2 = false;
                break;
            }
        }

        bool flag3 = true;
        int p = n-1;
        for(int j=s1.size()-1; j>=0; j--){
            if(x[p--]!=s1[j]){
                flag3 = false;
                break;
            }

        }

        bool flag4 = true;
        int q = n-1;
        for(int j=s2.size()-1; j>=0; j--){
            if(x[q--]!=s2[j]){
                flag4 = false;
                break;
            }

        }

        if(flag1==true&&flag4==true){
            arr[id1] = 0; arr[id2] = 1;
        }else if(flag2==true&&flag3==true){
            arr[id1] = 1; arr[id2] = 0;
        }else{
            ok = false;
            break;
        }
    }

    return ok;
}
string solve(string x){
    string ans;
    for(int i=1; i<=k; i++){
        if(arr[i]==0) ans+='P';
        else ans+='S';
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    k = (2*n)-2;
    for(int i=1; i<=k; i++){
        string x; cin>>x;
        a[i].s = x;
        a[i].id = i;
        a[i].len = x.size();
    }

    sort(a+1, a+k+1, cmp);

    string s1 = a[1].s;
    string s2 = a[2].s;

    string x;
    for(int i=0; i<(int)s1.size(); i++){
        x += s1[i];
    }
    x += s2[(int)s2.size()-1];

    string y;
    for(int i=0; i<(int)s2.size(); i++){
        y += s2[i];
    }
    y += s1[(int)s1.size()-1];

    if(possible(x)==true){
        string ans = solve(x);
        cout << ans << endl;
    }else if(possible(y)==true){
        string ans = solve(x);
        cout << ans << endl;
    }

    return 0;
}
