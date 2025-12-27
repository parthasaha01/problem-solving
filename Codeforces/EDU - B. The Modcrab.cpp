#include<bits/stdc++.h>
using namespace std;
vector<string>vv;
int main()
{
    int h1,a1,c1;
    int h2,a2;

    scanf("%d%d%d",&h1,&a1,&c1);
    scanf("%d%d",&h2,&a2);

    while(1)
    {
        int t2 = h2-a1;
        int t1 = h1-a2;
        if(t2>0 && t1<=0) // must heal
        {
            vv.push_back("HEAL");
            h1 += c1;
            h1 -= a2;
        }
        else
        {
            vv.push_back("STRIKE");
            h2 -= a1;
            h1 -= a2;
        }

        if(h2<=0)break;
    }

    int sz = vv.size();
    printf("%d\n",sz);

    for(int i=0; i<sz; i++){
        cout << vv[i] << endl;
    }

    return 0;
}
