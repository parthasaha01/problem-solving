#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;

    while(cin>>s)
    {
        int sz=s.size();
        int cl,cr,cu,cd;
        cl=cr=cu=cd=0;

        if(sz%2==1){
            printf("-1\n");
            continue;
        }

        for(int i=0; i<sz; i++){
            if(s[i]=='L'){
                cl++;
            }
            else if(s[i]=='R'){
                cr++;
            }
            else if(s[i]=='U'){
                cu++;
            }
            else{
                cd++;
            }
        }

        int dlr=abs(cl-cr);
        int dud=abs(cu-cd);

        int ans=(dlr+dud)/2;
        printf("%d\n",ans);

    }

    return 0;
}
