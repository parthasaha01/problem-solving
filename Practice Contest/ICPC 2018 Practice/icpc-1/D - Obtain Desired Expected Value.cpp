#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector< pair<int,int> >a;
double p[1005];
bool cmp(pii x, pii y){
    return x.first < y.first;
}
int main(){
    int tt; scanf("%d",&tt);
    while(tt--){
        int n,e; scanf("%d%d",&n,&e);
        a.clear();
        for(int i=0; i<n; i++){
            int x; scanf("%d",&x);
            a.push_back(make_pair(x,i));
        }
        sort(a.begin(),a.end(),cmp);

        if(e<a[0].first || e>a[n-1].first){
            printf("-1\n");
        }else{
            if(n==1){
                printf("%.10f\n",1.0);
            }else{
                for(int i=0; i<n; i++) p[i] = 0;
                if(a[0].first==a[n-1].first){
                    p[0] = 1.0;
                }else if(a[n-1].first==e){
                    p[a[n-1].second] = 1.0;
                }else if(a[0].first==e){
                    p[a[0].second] = 1.0;
                }else{
                    p[a[0].second] = (double)(a[n-1].first - e) / (double)(a[n-1].first-a[0].first);
                    p[a[n-1].second] = 1.0 - p[a[0].second];
                }

                for(int i=0; i<n; i++){
                    if(i<n-1)printf("%.10f ",p[i]);
                    else printf("%.10f\n",p[i]);
                }
            }
        }
    }
    return 0;
}
