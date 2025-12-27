#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int q;
string s;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>> q >> s;
    int n = s.size();
    int pos = n;
    for(int i=1; i<=q; i++)
    {
        int tp; cin>> tp;
        if(tp==1)
        {
            string c; cin>>c;

            if(c.size()>1){
                if((s.size()>0)&&(pos>0)){
                    s.erase(s.begin()+pos-1);
                    pos--;
                }
            }
            else{
                s.insert(s.begin()+pos,c[0]);
                pos++;
            }
        }
        else
        {
            int go; cin>>go;
            pos = go;
        }
    }

    cout << s << endl;

    return 0;
}

