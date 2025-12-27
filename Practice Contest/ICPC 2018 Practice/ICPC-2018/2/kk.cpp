#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
int n,sum[105];
int calc(vi p){
    int cnt = 0;
    memset(sum,0,sizeof(sum));
    for(int i=0; i<n; i++){
        sum[i+1] = sum[i]+p[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; i+j-1<=n; j++){
            cnt += sum[i+j-1]-sum[i-1];
        }
    }

    return cnt;
}
vi fun(vi p){
    int minn = 100000000;
    vi a;
    do{
        int cnt = calc(p);
        for(int i=0; i<p.size(); i++){
            printf("%d ",p[i]);
        }
        printf(" = %d\n",cnt);
        if(cnt<minn){
            a = p;
            //cout << a.size() << endl;
            minn = cnt;
        }

    }while(next_permutation(p.begin(), p.end()));
    //cout << a.size() << endl;
    return a;
}
int main()
{
    //freopen("cubes.in","r",stdin);
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        scanf("%d",&n);
        vector<int>v;
        for(int i=0; i<n; i++){
            int x; scanf("%d",&x);
            v.push_back(x);
        }
        sort(v.begin(), v.end());

        vi a = fun(v);
        //cout << a.size() << endl;
        printf("Case %d:\n",ks);
        for(int i=0; i<n; i++){
            if(i==n-1)printf("%d\n",a[i]);
            else printf("%d ",a[i]);
        }
    }
    return 0;
}

