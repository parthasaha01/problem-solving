#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

#define ll long long
#define pi 2*acos(0.0)
#define ull unsigned long long
#define all(v) v.begin(),v.end()

#define sii(t) scanf("%d",&t)
#define sll(t) scanf("%lld",&t)
#define ssii(a,b) scanf("%d%d",&a,&b)
#define ssll(a,b) scanf("%lld%lld",&a,&b)

int main()
{
    int t,no=0;
    sii(t);
    while(t--)
    {
        string s,add;
        printf("Case %d:\n",++no);
        s="";
        stack<string>st;
        stack<string>st1;
        add="http://www.lightoj.com/";
        st.push(add);
        while(cin>>s)
        {
            if(s[0]=='Q')
            break;

            if(s[0]=='V'){
                    cin>>add;
             cout<<add<<endl;
             st.push(add);
              if(!st1.empty())
              {
                  while(!st1.empty())
                    st1.pop();
              }
            }
            else
            {
                if(s[0]=='B')
                {
                    st1.push(st.top());
                    st.pop();
                    if(!st.empty()){
                     cout<<st.top()<<endl;
                    }
                    else{
                     printf("Ignored\n");
                     st.push(st1.top());
                     st1.pop();
                    }
                }
                else if(s[0]=='F')
                {
                    if(!st1.empty())
                    {
                        cout<<st1.top()<<endl;
                        st.push(st1.top());
                        st1.pop();
                    }
                    else
                    {
                        printf("Ignored\n");
                    }
                }
            }
        }
    }

    return 0;
}
