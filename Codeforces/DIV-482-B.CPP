#include<bits/stdc++.h>
using namespace std;
string s[5];
int a[200];
int main()
{
    int k; cin>>k;

    cin>>s[0];
    cin>>s[1];
    cin>>s[2];

    int n = s[0].size();


    int maxx = 0;
    memset(a,0,sizeof(a));
    for(int i=0; i<n; i++){
        a[s[0][i]]++;
        maxx = max(a[s[0][i]],maxx);
    }
   int  x = maxx;
   int xx = n-x;
   int p = min(n,x+k);

    maxx = 0;
    memset(a,0,sizeof(a));
    for(int i=0; i<n; i++){
        a[s[1][i]]++;
        maxx = max(a[s[1][i]],maxx);
    }
    int  y = maxx;
    int yy = n-y;
    int q = min(n,y+k);

    maxx = 0;
    memset(a,0,sizeof(a));
    for(int i=0; i<n; i++){
        a[s[2][i]]++;
        maxx = max(a[s[2][i]],maxx);
    }
    int  z = maxx;
    int zz = n-z;
    int r = min(n,z+k);

    if(k==1)
    {
        if(x==n)p=n-1;
        if(y==n)q=n-1;
        if(z==n)r=n-1;
    }

    //printf("x=%d p=%d y=%d q=%d z=%d r=%d\n",x,p,y,q,z,r);

    if(p>q && p>r){
        cout << "Kuro" << endl;
    }
    else if(q>p && q>r){
        cout << "Shiro" << endl;
    }
    else if(r>p && r>q){
        cout << "Katie" << endl;
    }
    else{
        cout << "Draw" << endl;
    }

    //main();

    return 0;

}
