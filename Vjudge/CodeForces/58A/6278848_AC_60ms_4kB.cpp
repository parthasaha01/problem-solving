#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;

    while(cin >> s)
    {
        int sz=s.size();
        int flag=0;
        char h[6]="hello";
        int k=0;
        for(int i=0; i<sz; i++)
        {
            if(s[i]==h[k]){
                k++;
                if(k>4){
                    flag=1;
                    break;
                }
            }
        }

        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
