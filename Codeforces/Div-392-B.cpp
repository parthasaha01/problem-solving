#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int main()
{
    string s;

    while(cin>>s)
    {
        int r,b,y,g;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='R'){
                r=i;
                break;
            }
        }
        for(int i=0; i<s.size(); i++){
            if(s[i]=='B'){
                b=i;
                break;
            }
        }
        for(int i=0; i<s.size(); i++){
            if(s[i]=='Y'){
                y=i;
                break;
            }
        }
        for(int i=0; i<s.size(); i++){
            if(s[i]=='G'){
                g=i;
                break;
            }
        }

        int rr = r%4;
        int bb = b%4;
        int yy = y%4;
        int gg = g%4;

        int cr=0,cb=0,cy=0,cg=0;

        for(int i=rr; i<s.size(); i+=4){
            if(s[i]=='!') cr++;
        }
        for(int i=bb; i<s.size(); i+=4){
            if(s[i]=='!') cb++;
        }
        for(int i=yy; i<s.size(); i+=4){
            if(s[i]=='!') cy++;
        }
        for(int i=gg; i<s.size(); i+=4){
            if(s[i]=='!') cg++;
        }

        printf("%d %d %d %d\n",cr,cb,cy,cg);
    }

    return 0;
}

