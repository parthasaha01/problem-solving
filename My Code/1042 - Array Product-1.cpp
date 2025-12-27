#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
struct data{
    int tp,ik,jk;
}st[MAXN];
vector<int>zero,pos,neg;
int n,a[MAXN];
void solve(){
    int zr = zero.size();
    int ps = pos.size();
    int ng = neg.size();
    int k = 0,flag=0;
    int maxNeg = -2000000000;
    int maxNegPos = -1;
    for(int i=0; i<neg.size(); i++){
        if(a[neg[i]]>maxNeg){
            maxNeg = a[neg[i]];
            maxNegPos = neg[i];
        }
    }

    if((int)neg.size()%2==0){
        for(int i=1; i<neg.size(); i++){
            ++k;
            st[k].tp = 1;
            st[k].ik = neg[i-1];
            st[k].jk = neg[i];
        }
    }
    else{
        vector<int>nn;
        for(int i=0; i<neg.size(); i++){
            if(neg[i]==maxNegPos)continue;
            nn.push_back(neg[i]);
        }
        neg.clear();
        neg = nn;
        ng = neg.size();

        for(int i=1; i<neg.size(); i++){
            ++k;
            st[k].tp = 1;
            st[k].ik = neg[i-1];
            st[k].jk = neg[i];
        }

        flag = 1;
        if((int)zero.size()==0){
            ++k;
            st[k].tp = 2;
            st[k].ik = maxNegPos;
            st[k].jk = maxNegPos;
        }
        else{
            ++k;
            st[k].tp = 1;
            st[k].ik = maxNegPos;
            st[k].jk = zero[0];
        }
    }
    //if(k==n-1)return;
    if((int)zero.size()==n){
        for(int i=1; i<zero.size(); i++){
            ++k;
            st[k].tp = 1;
            st[k].ik = zero[i-1];
            st[k].jk = zero[i];
        }
    }
    else if((int)zero.size()==0){
        if((int)neg.size()==0){
            for(int i=1; i<pos.size(); i++){
                ++k;
                st[k].tp = 1;
                st[k].ik = pos[i-1];
                st[k].jk = pos[i];
            }
        }
        else{
            if(pos.size()>0){
                ++k;
                st[k].tp = 1;
                st[k].ik = st[k-1].jk;
                st[k].jk = pos[0];
            }
            for(int i=1; i<pos.size(); i++){
                ++k;
                st[k].tp = 1;
                st[k].ik = pos[i-1];
                st[k].jk = pos[i];
            }
        }
    }
    else{
        if(flag==0){
            for(int i=1; i<zero.size(); i++){
                ++k;
                st[k].tp = 1;
                st[k].ik = zero[i-1];
                st[k].jk = zero[i];
            }

            if((int)zero.size()==1){
                ++k;
                st[k].tp = 2;
                st[k].ik = zero[0];
                st[k].jk = zero[0];
            }
            else{
                ++k;
                st[k].tp = 2;
                st[k].ik = st[k-1].jk;
                st[k].jk = st[k-1].jk;
            }

            if((int)pos.size()>0 && (int)neg.size()>0){
                ++k;
                st[k].tp = 1;
                st[k].ik = neg[(int)neg.size()-1];
                st[k].jk = pos[0];
            }

            for(int i=1; i<pos.size(); i++){
                ++k;
                st[k].tp = 1;
                st[k].ik = pos[i-1];
                st[k].jk = pos[i];
            }
        }
        else{
            for(int i=1; i<zero.size(); i++){
                ++k;
                st[k].tp = 1;
                st[k].ik = zero[i-1];
                st[k].jk = zero[i];
            }

            if((int)pos.size()>0){
                ++k;
                st[k].tp = 1;
                st[k].ik = st[k-1].jk;
                st[k].jk = pos[0];
            }
            for(int i=1; i<pos.size(); i++){
                ++k;
                st[k].tp = 1;
                st[k].ik = pos[i-1];
                st[k].jk = pos[i];
            }
        }
    }

//    if(k<n-1){
//        while(1){
//
//        }
//    }

    for(int i=1; i<=k; i++){
        if(st[i].tp==2){
            printf("%d %d\n",st[i].tp, st[i].ik);
        }
        else{
            printf("%d %d %d\n",st[i].tp, st[i].ik, st[i].jk);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        if(a[i]==0) zero.push_back(i);
        else if(a[i]<0) neg.push_back(i);
        else pos.push_back(i);
    }

    solve();

    return 0;
}

