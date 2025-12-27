#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int t,sx,sy,ex,ey,px,py,sz,flag,cnt;

    while(cin >>t>>sx>>sy>>ex>>ey)
    {
        cin >> s;
        sz=s.size();
        flag=0;
        cnt=0;
        px=sx;
        py=sy;

        if(px==ex && py==ey)
        {
            cout << "0" << endl;
            continue;
        }

        for(int i=0; i<sz; i++)
        {

            if(s[i]=='E')
            {
                if(px<ex){
                    px += 1;
                }
            }
            else if(s[i]=='W')
            {
                if(px>ex){
                    px -= 1;
                }
            }
            else if(s[i]=='N')
            {
                if(py<ey){
                    py += 1;
                }
            }
            else
            {
                if(py>ey){
                    py -= 1;
                }
            }

            if(px==ex && py==ey)
            {
                cnt = i+1;
                flag=1;
                break;
            }
        }

        if(flag)
        {
            cout << cnt << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }

    return 0;
}
