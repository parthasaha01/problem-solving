#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
string s,r,c;
string ss[5];
void fun(int row,int col){
    ss[0]="aeiou";
    ss[1]="eaoui";
    ss[2]="iouae";
    ss[3]="oueia";
    ss[4]="uiaeo";
    r = "aeiou";
    c = "aeiou";

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i<5&&j<5){
                s += ss[i][j];
            }else{
                if(i<5){
                    s += r[i];
                }else if(j<5){
                    s += c[j];
                }else{
                    s += 'z';
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    int f = 0;
    s.clear();
    for(int i=2; (i*i)<=n; i++) {
        if(n%i==0) {
            int ii = n/i;
            if(i>=5 && ii>=5){
                f = 1;
                fun(i,ii);
                break;
            }
        }
    }

    if(f){
        cout<<s<<endl;
    }else{
        cout<<"-1"<<endl;
    }

    main();

    return 0;

}

