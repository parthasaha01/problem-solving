#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k,r,d,a;
    char c;
    while(cin>>n>>m>>k)
    {
        if(k%2==0) c = 'R';
        else c = 'L';

        if(k%(2*m)==0) r = k/(2*m);
        else r = (k/(2*m))+1;

        if(k%2==0) a = ((r-1)*2*m)+2;
        else a = ((r-1)*2*m)+1;

        //cout << "a=" << a << endl;

        d = (k-a+2)/2;

        printf("%d %d %c\n",r,d,c);
    }

    return 0;
}
