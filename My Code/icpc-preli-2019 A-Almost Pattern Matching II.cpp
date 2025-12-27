#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define base 31LL

string s,p;
int k, sizeS, sizeP;
ll power[1200005], cum[1200005], hashS[1200005], hashP[1200005];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;

    power[0]=1; cum[0]=1;
    for(int i=1; i<=1200000; i++)
    {
        power[i] = (power[i-1]*base);
        cum[i] = (cum[i-1]+power[i]);
    }


    for(int ks=1; ks<=tt; ks++) {
        cin>>s>>p>>k;
        cout<<s<<" "<<p<<" "<<k<<endl;

        sizeS = s.size();
        sizeP = p.size();

        if(sizeS<sizeP){
            cout<<"Case "<<ks<<": 0"<<endl;
            continue;
        }

        for(int i=0; i<s.size(); i++) {
            if(i==0) {
                hashS[i] = s[i]*power[i];
            }else{
                hashS[i] = hashS[i-1] + (s[i]*power[i]);
            }
        }

        for(int i=0; i<p.size(); i++) {
            if(i==0) {
                hashP[i] = p[i]*power[i];
            }else{
                hashP[i] = hashP[i-1] + (p[i]*power[i]);
            }
        }

        for(int i=0; i<s.size(); i++) {

        }

    }
}
