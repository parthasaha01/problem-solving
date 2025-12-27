#include<bits/stdc++.h>
using namespace std;
int a[105];
string s[105];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        getchar();
        for(int i=0; i<n; i++){
            getline(cin,s[i]);
        }

        bool flag=true;
        for(int i=0; i<n; i++)
        {
            string ss=s[i];

            int cnt=0;

            for(int k=0; k<ss.size(); k++)
            {
                if(ss[k]=='a'||ss[k]=='e'||ss[k]=='i'||ss[k]=='o'||ss[k]=='u'||ss[k]=='y'){
                    cnt++;
                }
            }

            if(cnt!=a[i]){
                flag=false;
                break;
            }
        }

        if(flag){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

    return 0;
}
