#include<bits/stdc++.h>
using namespace std;
map< int, map<int, map<int,int> > > mp;
int vv[3];
int main()
{
    int n; scanf("%d",&n);

    int ans = 0;


    for(int a=1; a<=n; a++)
    {
        for(int b=1; b<=n; b++)
        {
            int c = a^b;

            if(c>n)continue;

            if(((a+b)>c) && ((b+c)>a) && ((a+c)>b))
            {
                //vv[0] = a;
                //vv[1] = b;
                //vv[2] = c;
                //sort(vv,vv+3);
                //if(mp[vv[0]][vv[1]][vv[2]]==0){
                    //cout << a << " " << b << " " << c << endl;
                    ans++;
                //}
                //mp[vv[0]][vv[1]][vv[2]] = 1;

                //cout << a << " " << b << " " << c << endl;

            }
        }
    }

    printf("%d\n",ans/6);

    return 0;
}

