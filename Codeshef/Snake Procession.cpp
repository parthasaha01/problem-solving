#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int r; scanf("%d",&r);

        string s; cin>>s;

        int id=2;

        for(int i=0; i<r; i++)
        {
            if(s[i]=='H'){
                if(id==1)break;
                else id=1;
            }
            else if(s[i]=='T'){
                if(id==2){id=1;break;}
                else id=2;
            }
        }

        if(id==2)printf("Valid\n");
        else printf("Invalid\n");
    }
    return 0;
}
