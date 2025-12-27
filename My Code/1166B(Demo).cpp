#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,f=0;
string s;
int cnt[10];
vector<vector<int>>ans;
map<int,char>mp;
void print() {
//    for(int i=0; i<5; i++) {
//        for(int j=0; j<5; j++) {
//            cout<<ans[i][j];
//        }
//        cout<<endl;
//    }
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cout<<mp[ans[i][j]];
        }
        cout<<endl;
    }
    cout<<endl;
    ans.clear();
}
int check(vector<vector<int>>xx) {
    int cc = 1;
    for(int i=0; i<5; i++){
        memset(cnt,0,sizeof(cnt));
        for(int j=0; j<5; j++){
            cnt[xx[i][j]]++;
        }
        for(int j=1; j<=5; j++) {
            if(cnt[j]==0)return 0;
        }
    }

    for(int i=0; i<5; i++){
        memset(cnt,0,sizeof(cnt));
        for(int j=0; j<5; j++){
            cnt[xx[j][i]]++;
        }
        for(int j=1; j<=5; j++) {
            if(cnt[j]==0)return 0;
        }
    }

    ans = xx;
    return 1;
}
int possible(int v,int row,int col, vector<vector<int>>xx){
    for(int i=0; i<5; i++){
        if(xx[row][i]==v)return 0;
    }

    for(int i=0; i<5; i++){
        if(xx[i][col]==v)return 0;
    }

    return 1;
}
void fun(int row,int col, vector<vector<int>>xx){
    if(f==10)return;
    if(row==5) {
        int ff = check(xx);
        if(ff==1){
            f++;
            print();
        }
        return;
    }
    //vector<vector<int>>temp;
    //temp = xx;
    if(col<4) {
        for(int i=1; i<=5; i++){
            if(possible(i,row,col,xx)){
                xx[row][col] = i;
                fun(row,col+1,xx);
                xx[row][col] = 0;
            }
        }
    }else{
        for(int i=1; i<=5; i++){
            if(possible(i,row,col,xx)){
                xx[row][col] = i;
                fun(row+1,0,xx);
                xx[row][col] = 0;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    mp[1] = 'a'; mp[2] = 'e'; mp[3] = 'i'; mp[4] = 'o'; mp[5] = 'u';

    vector<vector<int>>vv;
    for(int i=0; i<5; i++){
        vector<int>v;
        v.clear();
        for(int j=0; j<5; j++){
            v.push_back(0);
        }
        vv.push_back(v);
    }

    fun(0,0,vv);




    cout << f << endl;


    if(f){
//        for(int i=0; i<5; i++) {
//            for(int j=0; j<5; j++) {
//                cout<<ans[i][j];
//            }
//            cout<<endl;
//        }
//        for(int i=0; i<5; i++) {
//            for(int j=0; j<5; j++) {
//                cout<<mp[ans[i][j]];
//            }
//            cout<<endl;
//        }
    }else{
        cout<<"-1"<<endl;
    }

    //main();

    return 0;

}



