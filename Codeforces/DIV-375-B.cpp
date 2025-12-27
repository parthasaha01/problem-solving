#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n;

    while(cin>>n)
    {
        int ans1=0;
        int ans2=0;
        int len=0;

        bool braket=false;

        cin>>s;

        for(int i=0; i<n; i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                ans1=max(ans1,len);
                braket=true;
                len=0;
            }
            else if(s[i]==')'||s[i]=='}'||s[i]==']')
            {
                braket=false;
                if(isalpha(s[i-1])){
                    ans2++;
                }
                len=0;
            }
            else if(s[i]=='_')
            {
                if(braket==true)
                {
                    if(isalpha(s[i-1])){
                        ans2++;
                    }
                }
                else
                {
                    ans1=max(ans1,len);
                }

                len=0;
            }
            else if(isalpha(s[i])&&braket==false)
            {
                len++;
            }
        }

        ans1=max(ans1,len);

        printf("%d %d\n",ans1,ans2);
    }

    return 0;
}
