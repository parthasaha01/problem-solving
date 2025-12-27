#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
struct data{
    int tp,ik,jk;
}st[MAXN],sp[2];
vector<int>zero,pos,neg;
int n,k,x,a[MAXN];
void print(){
    for(int i=1; i<=k; i++){
        if(st[i].tp==2){
            printf("%d %d\n",st[i].tp, st[i].ik);
        }
        else{
            printf("%d %d %d\n",st[i].tp, st[i].ik, st[i].jk);
        }
    }
}
void solve(){
    int zr = zero.size();
    int ps = pos.size();
    int ng = neg.size();
    k = x = 0;
    int flag=0;
    int maxNeg = -2000000000;
    int maxNegPos = -1;
    for(int i=0; i<neg.size(); i++){
        if(a[neg[i]]>maxNeg){
            maxNeg = a[neg[i]];
            maxNegPos = neg[i];
        }
    }

    for(int i=1; i<zero.size(); i++){
        ++k;
        st[k].tp = 1;
        st[k].ik = zero[i-1];
        st[k].jk = zero[i];
        if(k==n-1)return;
    }
    for(int i=1; i<pos.size(); i++){
        ++k;
        st[k].tp = 1;
        st[k].ik = pos[i-1];
        st[k].jk = pos[i];
        if(k==n-1)return;
    }

    if((int)neg.size()%2==0){
        if((int)neg.size()>0){
            for(int i=1; i<neg.size(); i++){
                ++k;
                st[k].tp = 1;
                st[k].ik = neg[i-1];
                st[k].jk = neg[i];
                if(k==n-1)return;
            }
            if((int)pos.size()>0){
                ++k;
                st[k].tp = 1;
                st[k].ik = neg[(int)neg.size()-1];
                st[k].jk = pos[(int)pos.size()-1];
                if(k==n-1)return;
            }

        }
        if((int)zero.size()>0){
            ++k;
            st[k].tp = 2;
            st[k].ik = zero[(int)zero.size()-1];
            st[k].jk = zero[(int)zero.size()-1];
            if(k==n-1)return;
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
            if(k==n-1)return;
        }

        if((int)neg.size()>0){
            if((int)pos.size()>0){
                ++k;
                st[k].tp = 1;
                st[k].ik = neg[(int)neg.size()-1];
                st[k].jk = pos[(int)pos.size()-1];
                if(k==n-1)return;
            }
        }

        if((int)zero.size()>0){
            ++k;
            st[k].tp = 1;
            st[k].ik = maxNegPos;
            st[k].jk = zero[(int)zero.size()-1];
            if(k==n-1)return;

            ++k;
            st[k].tp = 2;
            st[k].ik = zero[(int)zero.size()-1];
            st[k].jk = zero[(int)zero.size()-1];
            if(k==n-1)return;

        }
        else{
            ++k;
            st[k].tp = 2;
            st[k].ik = maxNegPos;
            st[k].jk = maxNegPos;
            if(k==n-1)return;
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
    print();

    return 0;
}
