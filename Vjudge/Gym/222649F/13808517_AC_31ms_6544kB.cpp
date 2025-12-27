#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
string s[100005];
int a[100005];
vector<pii>p;
bool cmp(pii a,pii b)
{
    return a.first > b.first;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    int idx,maxx=0;
    for(int i=0; i<n; i++) {
        cin>>s[i];
        int sz = s[i].size();
        if(sz>maxx){
            maxx = sz;
            idx = i;
        }

        //p.push_back(mp(sz,i));
    }

    //sort(p,p+n,cmp);

    for(int i=0; i<s[idx].size(); i++){
        a[i] = s[idx][i];
    }

    int flag = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<s[i].size(); j++){
            if(s[i][j]!=a[j]){
                flag = 0;
                break;
            }
        }
        if(!flag)break;
    }

    if(flag)printf("%d\n",maxx);
    else printf("Impossible\n");

    return 0;

}
