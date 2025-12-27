#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
struct dt
{
    int tt;
    string ss;
}st[55];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1; i<=n; i++){
            cin >> st[i].tt >> st[i].ss;
        }

        bool flag = true;
        int p = 1;
        int ds = 0;

        for(int i=1; i<=n; i++)
        {
            int t = st[i].tt;
            string s = st[i].ss;

            if((ds==0 || ds==20000) && (s=="East" || s=="West")){
                flag = false;
                break;
            }
            if(ds==0 && s=="North"){
                flag = false;
                break;
            }
            if(ds==20000 && s=="South"){
                flag = false;
                break;
            }

            if(s=="North"){
                ds = ds - t;
                if(ds<0){
                    flag = false;
                    break;
                }
            }
            if(s=="South"){
                ds = ds + t;
                if(ds>20000){
                    flag = false;
                    break;
                }
            }
        }

        if(ds!=0) flag = false;

        if(flag){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}

