#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        string s;
        cin >> s;

        int v=0;
        int st=0;

        for(int i=0; i<n; i++)
        {
            if(s[i]=='G'){
                st=i;
                break;
            }
            else if(s[i]=='T') v++;
        }

        bool flag=false;

        if(v==0)
        {
            for(int i=st; i<n; i+=k){
                if(s[i]=='T'){
                    flag=true;
                    break;
                }
                else if(s[i]=='#') break;
            }
        }
        else
        {
            for(int i=st; i>=0; i-=k){
                if(s[i]=='T'){
                    flag=true;
                    break;
                }
                else if(s[i]=='#') break;
            }
        }

        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
