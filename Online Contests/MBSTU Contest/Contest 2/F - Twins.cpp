#include<bits/stdc++.h>
using namespace std;
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
        int total=0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            total+=a[i];
        }

        sort(a,a+n,cmp);

        int need = (total/2)+1;
        int cnt=0,sum=0;
        //cout << endl << total << " " << need << endl;
        for(int i=0; i<n; i++)
        {
            //cout << a[i] << " ";
            sum += a[i];
            if(sum>=need)
            {
                cnt = i+1;
                break;
            }
        }
        //cout << endl ;
        cout << cnt << endl;
    }

    return 0;
}
