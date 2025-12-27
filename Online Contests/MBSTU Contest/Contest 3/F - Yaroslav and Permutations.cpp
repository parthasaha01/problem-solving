#include<bits/stdc++.h>
using namespace std;
#define mx 1001
int fre[1005];
int a[105];
bool cmp(int x, int y)
{
    return x>y;
}
int main()
{
    int n;

    while(cin >> n)
    {
        memset(fre,0,sizeof(fre));

        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            fre[a[i]]++;
        }

        sort(fre,fre+mx,cmp);

        int maxx=fre[0];

        //cout << "maxx=" << maxx << endl;

        if(n&1)
            n++;

        if(maxx<=(n/2)){
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
