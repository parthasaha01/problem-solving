#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 300005;
struct Node{
    int nxt[26];
    int val;
    int length, suffixLink;
    int startPos, endPos;
};
struct PalTree{
    Node tree[MAXN];
    Node root1, root2;
    int ptr, curNode;
    int ans = 0;
    char s[MAXN];

    void init(){
        root1.length = -1, root1.suffixLink = 1;
        root2.length =  0, root2.suffixLink = 1;
        tree[1] = root1, tree[2] = root2;
        ptr = curNode = 2;
    }

    void addLetter(int pos){
        int ch = s[pos]-'a';
        int cur = curNode;

//        int tmp = curNode;
//        while(true){
//            int tmpLength = tree[tmp].length;
//            if(pos-1-tmpLength >= 0 && s[pos-1-tmpLength] == s[pos]){
//                tree[tmp].num[ch]++;
//                int cnt = tree[tmp].num[ch];
//                int len = tree[tmp].length + 2;
//                int val = cnt*len;
//                ans = max(ans,val);
//            }
//            if(tmpLength==-1)break;
//            tmp = tree[tmp].suffixLink;
//        }

        while(true){
            int curLength = tree[cur].length;
            if(pos-1-curLength >= 0 && s[pos-1-curLength] == s[pos])break;
            cur = tree[cur].suffixLink;
        }

        if(tree[cur].nxt[ch] != 0){
            curNode = tree[cur].nxt[ch];
            tree[curNode].val++;
            return;
        }

        ptr++;
        curNode = ptr;
        tree[cur].nxt[ch] = curNode;
        tree[curNode].length = tree[cur].length + 2;
        tree[curNode].startPos = pos - tree[curNode].length + 1;
        tree[curNode].endPos = pos;

        if(tree[curNode].length == 1){
            tree[curNode].suffixLink = 2;
            tree[curNode].val = 1;
            return;
        }


        while(true){
            cur = tree[cur].suffixLink;
            int curLength = tree[cur].length;
            if(pos-1-curLength >= 0 && s[pos-1-curLength] == s[pos]){
                tree[curNode].suffixLink = tree[cur].nxt[ch];
                break;
            }
        }

        tree[curNode].suffixLink = tree[cur].nxt[ch];
        tree[curNode].val = 1;
        return;
    }

    ll getResult(){
        ll ans = 0;
        for(int i=ptr; i>=1; i--){
            ll sum = (ll)tree[i].val * tree[i].length;
            ans = max(ans, sum);
            tree[tree[i].suffixLink].val += tree[i].val;
        }
        return ans;
    }

    void Clear(){
        for(int i=0; i<=ptr; i++){
            memset(tree[i].nxt, 0, sizeof(tree[i].nxt));
        }
    }
};
PalTree Pt;
int main()
{
    scanf("%s",&Pt.s);
    int n = strlen(Pt.s);
    Pt.init();
    for(int i=0; i<n; i++) Pt.addLetter(i);
    ll ans = Pt.getResult();
    printf("%lld\n",ans);

    return 0;
}

