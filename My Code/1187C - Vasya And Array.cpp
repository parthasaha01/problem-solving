#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector< pair<int,int> >a;
vector< pair<int,int> >b;
vector< pair<int,int> >aa;
vector< pair<int,int> >bb;
int ans[1005];
int n,m, col[1005];
bool isOverlap(pii x, pii y){
    if(y.first>x.second)return false;
    return true;
}
bool cmp(pii x, pii y) {
    if(x.first == y.first){
        return x.second < y.second;
    }
    return x.first < y.first;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;

    for(int i=1; i<=m; i++){
        int t,l,r; cin>>t>>l>>r;
        if(l>r)swap(l,r);

        if(t==1) {
            a.push_back(make_pair(l,r));
        }else{
            b.push_back(make_pair(l,r));
        }
    }

    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);

    for(int i=0; i<a.size(); i++) {
        if(i==0){
            aa.push_back(a[i]);
        }else{
            pii x = aa[aa.size()-1];
            pii y = a[i];

            if(isOverlap(x,y)){
                pii z = make_pair(min(x.first,y.first), max(x.second,y.second));
                aa[aa.size()-1] = z;
            }else{
                aa.push_back(y);
            }
        }
    }

    for(int i=0; i<b.size(); i++) {
//        if(i==0){
//            bb.push_back(b[i]);
//        }else{
//            pii x = bb[bb.size()-1];
//            pii y = b[i];
//
//            if(isOverlap(x,y)){
//                pii z = make_pair(min(x.first,y.first), max(x.second,y.second));
//                bb[bb.size()-1] = z;
//            }else{
//                bb.push_back(y);
//            }
//        }
        bb.push_back(b[i]);
    }

    memset(col,0,sizeof(col));

    for(int i=0; i<aa.size(); i++) {
        for(int j=aa[i].first; j<=aa[i].second; j++) {
            col[j] = i+1;
        }
    }

    bool flag = true;

    for(int i=0; i<bb.size(); i++) {
        set<int>ss;
        if(bb[i].second-bb[i].first>0){
            for(int j=bb[i].first; j<=bb[i].second; j++) {
                ss.insert(col[j]);
            }
            if(ss.size()==1){
                if(*(ss.begin())!=0){
                    flag = false;
                    break;
                }
            }
        }

        if(flag==false){
            break;
        }
    }

    if(flag==true){
        cout<<"YES"<<endl;
        int minn = 1000000005;
        for(int i=0; i<aa.size(); i++){
            for(int j=aa[i].first; j<=aa[i].second; j++) {
                ans[j] = 100000000-(i*2005);
                minn = min(ans[j],minn);
            }
        }

        int cur = minn-100;

        for(int i=0; i<bb.size(); i++) {
            if(ans[bb[i].first]==0 && ans[bb[i].first+1] != 0) {
                ans[bb[i].first] = ans[bb[i].first+1]+1;
            }
            for(int j=bb[i].first; j<=bb[i].second; j++) {
                if(ans[j]==0) {
                    ans[j] = --cur;
                }
            }
        }

        for(int i=1; i<=n; i++){
            if(ans[i]==0){
                ans[i] = --cur;
            }
        }

        for(int i=1; i<=n; i++){
            if(i==n){
                cout<<ans[i]<<endl;
            }
            else{
                cout<<ans[i]<<" ";
            }

        }
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
