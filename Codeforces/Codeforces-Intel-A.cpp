#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int main()
{
    int type;
    string s;
    while(cin >> type)
    {
        cin >> s;
        int h1,h2,m1,m2;
        h1=s[0]-'0';
        h2=s[1]-'0';
        m1=s[3]-'0';
        m2=s[4]-'0';

        if(type==12)
        {
            if(h1!=1){
                h1=0;
            }
            if(h1!=0){
                if(h2>2){
                    h2=0;
                }
            }
            if(m1>5){
                m1=1;
            }

            if(h1==0&&h2==0){
                h2=1;
            }

            cout << h1 << h2 << ":" << m1 << m2 << endl;
        }
        else
        {
            if(h1!=0 && h1!=1 && h2!=2){
                h1=1;
            }

            if(h1==2){
                //cnt++;
                if(h2>3){
                    h2=1;
                }
            }
            if(m1>5){
                m1=1;
                //cnt++;
            }

            cout << h1 << h2 << ":" << m1 << m2 << endl;
        }
    }

    return 0;
}
