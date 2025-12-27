#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long int
string s[1005];
int main()
{
    int n;

    while(cin>>n)
    {
        for(int i=0; i<n; i++){
            cin>>s[i];
        }
        bool flag=false;
        for(int i=0; i<n; i++)
        {
            if((s[i][0]=='O'&&s[i][1]=='O')){
                flag=true;
                s[i][0]='+';
                s[i][1]='+';
                break;
            }
            if((s[i][3]=='O'&&s[i][4]=='O'))
            {
                flag=true;
                s[i][3]='+';
                s[i][4]='+';
                break;
            }
        }

        if(flag==true){
            printf("YES\n");
            for(int i=0; i<n; i++){
                cout << s[i] << endl;
            }
        }
        else{
            printf("NO\n");
        }
    }

    return 0;
}
