#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        string s;
        cin>>s;
        bool flag=true;
        char ch=s[0];
        for(int i=2; i<s.size(); i+=2)
        {
            if(s[i]!=ch){
                flag=false;
                break;
            }
        }

        if(flag)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
