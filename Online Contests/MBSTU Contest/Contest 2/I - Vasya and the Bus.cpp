#include<bits/stdc++.h>
using namespace std;
int main()
{
    int g,c,maxx,minn;

    while(cin >> g >> c)
    {
        if(g==0){
            if(c==0){
                cout << "0" << " " << "0" << endl;
            }
            else{
                cout << "Impossible" << endl;
            }
            continue;
        }
        if(c==0)
        {
            cout << g << " " << g << endl;
            continue;

        }

        maxx=g+c-1;

        if(g>=c){
            minn=g;
        }
        else
        {
            minn = c;
        }

        cout << minn << " " << maxx << endl;

    }

    return 0;
}
