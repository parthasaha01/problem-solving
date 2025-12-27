#include<bits/stdc++.h>
using namespace std;
double EPS = 1e-12;
int main()
{
    string s;
    while(cin>>s)
    {
        int n = s.size();
        int zero=0,one=0;

        for(int i=0; i<n; i++){
            if(s[i]=='0')zero++;
            else one++;
        }

        double rot=0.0,shoot=0.0;
        rot = (one/(double)n);

        for(int i=0; i<n; i++){
            if(i==0){
                if(s[i]=='0'){
                    if(s[n-1]=='1'){
                        shoot += (1.0/double(zero));
                    }
                }
            }
            else{
                if(s[i]=='0'){
                    if(s[i-1]=='1'){
                        shoot += (1.0/double(zero));
                    }
                }
            }
        }

        if(fabs(shoot-rot)<EPS){
            cout << "EQUAL" << endl;
        }
        else if(rot<shoot){
            cout << "ROTATE" << endl;
        }
        else{
            cout << "SHOOT" << endl;
        }
    }
    return 0;
}
