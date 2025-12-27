#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define vi vector<int>
ll n,flag=0;
vector<int>even;
vector<int>odd;
vector<int>a;
int calc(int pos,int sum1,int sum2, vi x, vi y)
{
    if(pos>n){
        int gcd = __gcd(sum1,sum2);
        if(sum1==0)return 0;
        if(sum2==0)return 0;
        if(gcd>1){
            if(flag==0){
            for(int i=0; i<x.size(); i++){
                cout << x[i] << " ";
            }
            cout << endl;
            for(int i=0; i<y.size(); i++){
                cout << y[i] << " ";
            }
            cout << endl << endl;
            }
            flag++;
            return 1;

        }
        else return 0;
    }

    //if(dp[pos][sum1][sum2]!=-1)return dp[pos][sum1][sum2];
    vi xx = x;
    vi yy = y;
    xx.push_back(pos);
    yy.push_back(pos);
    int ret1 = calc(pos+1,sum1+pos,sum2,xx,y);
    int ret2 = calc(pos+1,sum1,sum2+pos,x,yy);

    int ret = ret1 | ret2;
    return ret;
}
void fun()
{
    flag = 0;
    even.clear();
    odd.clear();

    if(n<=2){
        cout << "No" << endl;
        return;
    }

    ll sum = (n*(n+1))/2;
    if(sum%2==0){
        even.push_back(2);
        for(int i=1; i<=n; i++){
            if(i!=2)odd.push_back(i);
        }

        cout<<"Yes"<<endl;

        int k1 = (int)even.size();
        cout<< k1;
        for(int i=0; i<k1; i++){
            cout << " " << even[i];
        }
        cout<<endl;

        int k2 = (int)odd.size();
        cout<< k2;
        for(int i=0; i<k2; i++){
            cout << " " << odd[i];
        }
        cout<<endl;
    }
    else{
//        a.clear();
//        for(int i=1; i<=n; i++)a.push_back(i);
//        vi x,y;
//        int ret = calc(1,0,0,x,y);
//        cout << ret << endl;

        cout<<"Yes"<<endl;

        for(int i=1; i<n; i++){
            odd.push_back(i);
        }
        even.push_back(n);


        int k2 = (int)odd.size();
        cout<< k2;
        for(int i=0; i<k2; i++){
            cout << " " << odd[i];
        }
        cout<<endl;

        int k1 = (int)even.size();
        cout<< k1;
        for(int i=0; i<k1; i++){
            cout << " " << even[i];
        }
        cout<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;

   fun();

    //cout << ans << endl;

    //main();
    return 0;
}

