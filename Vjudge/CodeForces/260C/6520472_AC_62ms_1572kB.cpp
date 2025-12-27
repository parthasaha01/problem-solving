#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100005
ll a[mx],b[mx];
int main()
{
    ll n,x,sub,dis;
    while(scanf("%I64d%I64d",&n,&x)==2)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%I64d",&a[i]);
            b[i]=a[i];
        }
        ll minn=9999999999;
        ll pos=0;
        /*for(int i=1; i<=n; i++){
            if(a[i]<=minn){
                minn=a[i];
                pos=i;
            }
        }
        //cout << pos << endl;
        if(a[x]==a[pos]){
            pos=x;
        }*/

        for(int i=x; i>0; i--){
            if(a[i]<minn){
                minn=a[i];
                pos=i;
            }
        }

        int flag=0;

        for(int i=x+1; i<=n; i++){
            if(a[i]<minn || (flag && a[i]<=minn)){
                flag=1;
                minn=a[i];
                pos=i;
            }
        }

        /*if(a[x]==a[pos]){
            pos=x;
        }*/

        if(x>=pos){
            dis=x-pos;
            sub=a[pos];

            for(int i=1; i<pos; i++){
                b[i]=a[i]-sub;
            }
            b[pos]=(a[pos]*n)+dis;
            sub=a[pos]+1;
            for(int i=pos+1; i<=x; i++){
                b[i]=a[i]-sub;
            }
            sub=a[pos];
            for(int i=x+1; i<=n; i++){
                b[i]=a[i]-sub;
            }
        }
        else{
            dis = (n-pos)+x;
            sub=a[pos]+1;
            for(int i=1; i<=x; i++){
                b[i]=a[i]-sub;
            }
            sub=a[pos];
            for(int i=x+1; i<pos; i++){
                b[i]=a[i]-sub;
            }
            b[pos]=(a[pos]*n)+dis;
            sub=a[pos]+1;
            for(int i=pos+1; i<=n; i++){
                b[i]=a[i]-sub;
            }
        }

        for(int i=1; i<=n; i++){
            if(i==n){
                printf("%I64d\n",b[i]);
            }
            else{
                printf("%I64d ",b[i]);
            }
        }

    }

    return 0;

}
/*
5 1
3 2 1 2 7
5 2
3 2 1 2 7
5 2
4 3 1 6 7
5 5
6 8 5 9 7
8 3
4 3 2 2 2 2 6 7
8 5
4 3 1 1 1 1 6 7
8 2
4 3 2 2 2 2 6 7
8 7
4 3 2 2 2 2 6 7
6 3
4 3 1 1 6 7
9 4
5 2 2 3 4 5 2 2 6
5 3
1 1 4 1 1
*/
