#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,flag,sub,cnt,st;

    while(cin >> N)
    {
        cnt=N;
        st=1;
        cout << st;
        --cnt;
        sub=N-1;
        flag=1;
        while(cnt!=0)
        {
            if(flag)
            {
                st=st+sub;
                cout <<" " << st;
                flag=0;
                --cnt;
                --sub;
            }
            else
            {
                st=abs(st-sub);
                cout <<" " << st;
                flag=1;
                --cnt;
                --sub;
            }
        }
        cout << endl;

    }

    return 0;
}
