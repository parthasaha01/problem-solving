#include<bits/stdc++.h>
using namespace std;
int a[15],m,n;
int call(int pos, int digit)
{
    int ret=0;
    if(pos==n)
        return 1;
    for(int i=0; i<m; i++)
    {
        if(abs(digit-a[i])<=2){
            ret += call(pos+1,a[i]);
        }
    }

    return ret;
}
int main()
{
    int T,test,cnt;
    cin >> T;

    for(test=1; test<=T; test++)
    {
        cin >> m >> n;
        cnt=0;

        for(int i=0; i<m; i++)
            cin >> a[i];

        for(int i=0; i<m; i++){
            cnt += call(1,a[i]);
        }

        cout<<"Case "<<test<<": "<<cnt<<endl;
    }

    return 0;
}
