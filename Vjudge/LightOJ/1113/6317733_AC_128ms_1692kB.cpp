#include<bits/stdc++.h>
using namespace std;
stack<string>b;
stack<string>f;
string s,ss,cur;
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        while(!b.empty()){
            b.pop();
        }
        while(!f.empty()){
            f.pop();
        }
        printf("Case %d:\n",kase);
        cur = "http://www.lightoj.com/";

        while(cin>>s)
        {
            if(s=="QUIT"){
                break;
            }
            else if(s=="VISIT")
            {
                cin >> ss;
                b.push(cur);
                cur=ss;
                cout << cur << endl;

                while(!f.empty())
                {
                    f.pop();
                }
            }
            else if(s=="BACK")
            {
                if(b.empty())
                {
                    cout << "Ignored" << endl;
                }
                else
                {
                    f.push(cur);
                    cur=b.top();
                    b.pop();
                    cout << cur << endl;
                }
            }
            else
            {
                if(f.empty())
                {
                    cout << "Ignored" << endl;
                }
                else
                {
                    b.push(cur);
                    cur=f.top();
                    f.pop();
                    cout << cur << endl;
                }
            }
        }
    }

    return 0;
}
