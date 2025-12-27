/// use FAST IO(cin/cout), instead of (scanf/printf)
/// otherwise will get TLE
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 5000003;
struct Node{
    int nxt[2];
    int length, suffixLink;
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
            return 0;
        }

        ptr++;
        curNode = ptr;
        tree[cur].nxt[ch] = curNode;
        tree[curNode].length = tree[cur].length + 2;

        if(tree[curNode].length == 1){
            tree[curNode].suffixLink = 2;
            return 1;
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
        return 1;
    }
};
PalTree Pt;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //scanf("%s",&Pt.s);
    cin>>Pt.s;
    int n = strlen(Pt.s);
    Pt.init();
    for(int i=0; i<n; i++) {
        //printf("%d",Pt.addLetter(i));
        cout<<Pt.addLetter(i);
    }
    //printf("\n");
    cout<<endl;

    return 0;
}
