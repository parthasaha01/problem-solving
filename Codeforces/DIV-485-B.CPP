#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll x,y;
    cin>>x>>y;
    if((x==y) || (x==2&&y==4) || (x==4&&y==2)){
        cout << "=" << endl;
    }
    else if(x==1 || y==1){
        if(x==1)cout << "<" << endl;
        else cout << ">" << endl;
    }
    else{
        if(x==2 || y==2){
            if(x==2 && y==3){
                cout << "<" << endl;
            }
            else if(x==3 && y==2){
                cout << ">" << endl;
            }
            else{
                if(x==2){
                    cout << ">" << endl;
                }
                else{
                    cout << "<" << endl;
                }
            }
        }
        else{
            if(x<y)cout << ">" << endl;
            else cout << "<" << endl;
        }
    }
    //main();
    return 0;
}

