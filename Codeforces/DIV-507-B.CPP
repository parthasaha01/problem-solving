#include<bits/stdc++.h>
using namespace std;
int n,k;
int vv[1005];
int fun()
{
    int x = 2*k+1;
    int cnt = 0;
    if(n%x==0){
        cnt = n/x;
        vv[1] = k+1;
        for(int i=2; i<=cnt; i++){
            vv[i] = vv[i-1] + x;
        }
    }
    else{

        int mm = x*(n/x);
        int yy = n-mm;
        int y = (yy-1)/2;

        cnt = (n/x) + 1;
        int nn = cnt*x;
        int dd = nn-n;
        int d = dd/2;

        vv[1] = 1+y;
        for(int i=2; i<=cnt; i++){
            vv[i] = vv[i-1]+x;
        }
    }

    cout<<cnt<<endl;
    for(int i=1; i<=cnt; i++){
        if(i==cnt)cout<<vv[i]<<endl;
        else cout<<vv[i]<<" ";
    }

}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>k;

    fun();

    //main();

    return 0;
}

