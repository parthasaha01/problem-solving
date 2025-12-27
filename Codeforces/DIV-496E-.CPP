#include<bits/stdc++.h>
using namespace std;
int n,m,p,a[200005],b[200005];
vector< pair<int,int> > v;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        b[a[i]] = i;
        if(a[i]==m){
            p = i;
        }
    }

//    for(int l=1; l<=n; l++){
//        for(int r=l; r<=n; r++){
//            if(l<=p&&p<=r){
//                int d = r-l+1;
//                int sm=0;
//                int bg=0;
//                for(int k=l; k<=r; k++){
//                    if(a[k]<m)sm++;
//                    if(a[k]>m)bg++;
//                }
//
//                if(d%2==1){
//                    if(sm==bg){
//                        v.push_back(make_pair(l,r));
//                    }
//                }
//                else{
//                    if(sm==bg-1){
//                        v.push_back(make_pair(l,r));
//                    }
//                }
//            }
//        }
//    }
//
//    cout << v.size() << endl;
//    for(int i=0; i<v.size(); i++){
//        cout <<"("<<v[i].first<<","<<v[i].second<<")"<<"  ";
//    }
//    cout << endl;



    return 0;
}
