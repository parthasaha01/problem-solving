#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,ss,sss;

    while(cin >> s)
    {
        int sz=s.size();
        ss=s;
        sss=s;

        sort(ss.begin(),ss.end());
        char ch=ss[0];

        if(ch=='a')
        {
            bool flag=false;

            for(int i=0; i<sz; i++)
            {
                if(s[i]==ch)
                {
                    if(flag==true)
                    {
                        break;
                    }

                }
                else
                {
                    flag=true;
                    s[i]=s[i]-1;
                }
            }
        }
        else
        {
            for(int i=0; i<sz; i++){
                s[i]=s[i]-1;
            }
        }

        if(sss==s)
        {
            if(s[sz-1]=='a'){
                s[sz-1]='z';
            }
            else{
                s[sz-1]=s[sz-1]-1;
            }
        }

        cout << s << endl;
    }

    return 0;
}
