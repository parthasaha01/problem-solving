#include<bits/stdc++.h>
using namespace std;
int a[12];
bool cmp(int x, int y)
{
    return x>y;
}
int main()
{
    int k;

    while(cin >> k)
    {
        for(int i=0; i<12; i++){
            cin >> a[i];
        }

        sort(a,a+12,cmp);

        int p=0;
        int cnt=0;
        int i=0;
        while(p<k && i<12)
        {
            ++cnt;
            p += a[i++];
        }

        if(p<k){
            cnt=-1;
        }

        cout << cnt << endl;
    }

    return 0;
}
