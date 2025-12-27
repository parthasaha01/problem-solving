/*
* Allah is Almighty.......
*
* Mehedi Hasan Angkur <thisisangkur@gmail.com>
* CSE 11th Batch,MBSTU
* uva,cf id mbstu_angkur..
*
* keep coding...
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define D double
#define pb push_back
#define mpp make_pair
#define sf scanf
#define pf prllf
#define ff first
#define ss second
#define sz 100005
#define sq(x) x*x
#define eps 1e-8
#define PI (2*acos(0.0))
#define mem(a, b) memset(a, b, sizeof a)
#define dist(x1, y1, x2, y2) sqrt(sq(x1-x2)+sq(y1-y2))
#define FastIO ios_base::sync_with_stdio(0)
const int inf = 0x7f7f7f7f;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};



int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    FastIO;
    int n,m,t;
    int cas = 1;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        int desx,desy;
        cin>>desx>>desy;
        int sq;
        cin>>sq;
        string st;
        cin>>st;
        int x=0,y=0;
        for(int i=0; i<st.size(); i++)
        {
            if(st[i]=='R')
            {
                x+=dx[0];
                y+=dy[0];
            }
            else if(st[i]=='L')
            {
                x+=dx[1];
                y+=dy[1];
            }
                else if(st[i]=='U')
            {
                x+=dx[2];
                y+=dy[2];
            }
             else if(st[i]=='D')
            {
                x+=dx[3];
                y+=dy[3];
            }
          //  cout<<st[i]<<" "<<x<<" "<<y<<endl;
        }
        //cout<<x<<" "<<y<<" "<<desx<<" "<<desy<<endl;
        if(x==desx && y==desy)
            cout<<"Case "<<cas++<<": REACHED"<<endl;
                else if(x<0 || x>m || y<0 || y>n)
            cout<<"Case "<<cas++<<": DANGER"<<endl;
            else
            cout<<"Case "<<cas++<<": SOMEWHERE"<<endl;

    }
    return 0;
}





