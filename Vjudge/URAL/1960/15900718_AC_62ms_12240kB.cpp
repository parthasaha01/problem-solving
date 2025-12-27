#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 100005;
struct Node{
    int nxt[26];
    int length, suffixLink;
    int startPos, endPos;
};
struct PalTree{
    Node tree[MAXN];
    Node root1, root2;
    int ptr, curNode;
    char s[MAXN];

    void init(){
        root1.length = -1, root1.suffixLink = 1;
        root2.length =  0, root2.suffixLink = 1;
        tree[1] = root1, tree[2] = root2;
        ptr = curNode = 2;
    }

    int addLetter(int pos){
        int ch = s[pos]-'a';
        int cur = curNode;

        while(true){
            int curLength = tree[cur].length;
            if(pos-1-curLength >= 0 && s[pos-1-curLength] == s[pos])break;
            cur = tree[cur].suffixLink;
        }

        if(tree[cur].nxt[ch] != 0){
            curNode = tree[cur].nxt[ch];
            return ptr-2;
        }

        ptr++;
        curNode = ptr;
        tree[cur].nxt[ch] = curNode;
        tree[curNode].length = tree[cur].length + 2;
        tree[curNode].startPos = pos - tree[curNode].length + 1;
        tree[curNode].endPos = pos;

        if(tree[curNode].length == 1){
            tree[curNode].suffixLink = 2;
            return ptr-2;
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
        return ptr-2;
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
    for(int i=0; i<n; i++) {
        int ans = Pt.addLetter(i);
        if(i==n-1)printf("%d\n",ans);
        else printf("%d ",ans);
    }

    return 0;
}