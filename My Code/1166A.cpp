#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
string s;
int cnt[30];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(cnt,0,sizeof(cnt));
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>s;
        cnt[s[0]-'a']++;
    }

    int x = 0;
    for(int i=0; i<26; i++) {
        if(cnt[i]>2) {
            if(cnt[i]%2==0) {
                int v = cnt[i]/2;
                x += v*(v-1);
            }else{
                int v = cnt[i]/2;
                x += (v*v);
            }
        }
    }

    printf("%d\n",x);

    main();

    return 0;

}
