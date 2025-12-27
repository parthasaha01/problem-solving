#include<bits/stdc++.h>
using namespace std;
#define LL long long
string fun(LL n)
{

    while(n!=0) {

    }
}


int main()
{
    int t; scanf("%d", &t);
    while(t--) {
        string s; cin>>s;
        int len = s.size();
        LL num = 0;
        for(int i=0; i<len; i++) {
            int d = s[i]-'0';
            num = num*10 + d;
        }

        //cout<<num<<endl;

        LL cal = 0;
        for(int i=0; i<len; i++) {
            int d = s[i]-'0';
            LL t = 1;
            for(int j=0; j<len; j++) t *= d;

            //cout<<t<<endl;

            cal += t;
        }

        //cout<<cal<<"    "<<num<<endl;

        if(cal==num) cout<<"Armstrong"<<endl;
        else cout<<"Not Armstrong"<<endl;
    }
}
