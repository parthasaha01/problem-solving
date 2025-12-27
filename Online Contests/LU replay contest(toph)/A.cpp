#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,ss;

    while(getline(cin,ss))
    {
        if(ss==""){
            printf("\n");
            continue;
        }

        s="";
        for(int i=0; i<ss.size(); i++){
            if(ss[i]!=' ')s+=ss[i];
        }
        cout << s << endl;
    }
    return 0;
}
