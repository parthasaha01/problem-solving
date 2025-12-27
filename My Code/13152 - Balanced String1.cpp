#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n; scanf("%d",&n);
        map<ll,int>mp;
        for(int i=1; i<=n; i++){
            ll x; scanf("%lld",&x);
            mp[x]++;
        }

        string ss;
        bool flag = true;
        ll st = 1;
        ll v = 1;
        for(int i=1; i<=n; i++){
            if(mp[st]>0){
                mp[st]--;
                if(v==1) ss += '(';
                else if(v==0) ss += ')';

                if(mp[st+1]>0){
                    st++;
                    v = 1;
                }
                else{
                    if(st==0 && i!=n){
                        flag = false;
                        break;
                    }
                    else{
                        st--;
                        v = 0;
                    }
                }
            }
            else{
                flag = false;
                break;
            }
        }

        if(ss.size() != n) flag = false;

        printf("Case %d: ",ks);
        if(flag) cout << ss << endl;
        else cout << "invalid" << endl;
    }
    return 0;
}
