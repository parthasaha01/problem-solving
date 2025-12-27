#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int n,flag,cnt,res;

    while(cin >> s)
    {
        n = s.size();
        flag=0;
        for(int p=n-1; p>0; p--)
        {
            for(int i=0; i<n-p; i++)
            {
                for(int j=i+1; j<=n-p; j++)
                {
                    cnt=0;
                    for(int k=0; k<p; k++)
                    {
                        if(s[i+cnt]==s[j+cnt])
                        {
                            ++cnt;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if(cnt==p)
                    {
                        flag=1;
                        res=p;
                        goto label;
                    }
                }
            }
        }

        label:

        if(flag==0)
            res=0;

        cout << res << endl;
    }

    return 0;
}

