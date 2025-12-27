#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,g,b,time,ar,minn,total;

    while(cin >> r >> g >> b)
    {
        total=r+g+b;
        time=0;
        ar=0;
        while(total>0)
        {
            if(ar%3==0){
                if(r>0)
                {
                    minn=min(r,2);
                    total -= minn;
                    r -= minn;
                }
            }
            else if(ar%3==1)
            {
                if(g>0)
                {
                    minn=min(g,2);
                    total -= minn;
                    g -= minn;
                }
            }
            else
            {
                if(b>0)
                {
                    minn=min(b,2);
                    total -= minn;
                    b -= minn;
                }
            }
            time=ar;
            ar++;
        }

        time += 30;

        cout << time << endl;
    }

    return 0;
}
