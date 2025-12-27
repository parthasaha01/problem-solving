/* You are given a string S. We want to know how many distinct substring of S which is palindrome.*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
struct Node{
    int nxt[26];
    int length;
    int suffixLink;
    int startPos, endPos;
};
struct PalTree{
    Node tree[MAXN];
    Node root1, root2;
    char s[MAXN];
    int curNode,ptr;

    void init() {
        root1.length= -1, root1.suffixLink = 1;
        root2.length = 0, root2.suffixLink = 1;
        tree[1] = root1, tree[2] = root2;
        curNode = ptr = 2;
    }

    bool addLetter(int pos) {
        getchar();
        printf("POSITION = %d\n",pos);

        int ch = s[pos]-'a';
        int cur = curNode;
        printf("B-cur = %d\n",cur);
        while(true) {
            int curLength = tree[cur].length;
            printf("curLength = %d, pos-1-curLength = %d,  s[%d] = %c s[%d] = %c\n",curLength,pos-1-curLength,pos-1-curLength,s[pos-1-curLength],pos,s[pos]);
            if(pos-1-curLength >= 0 && s[pos-1-curLength] == s[pos]) break;
            cur = tree[cur].suffixLink;
            printf("cur = %d\n",cur);
        }

        printf("F-cur = %d\n",cur);

        if(tree[cur].nxt[ch] != 0){
            curNode = tree[cur].nxt[ch];
            printf("Duplicate curNode = %d\n",curNode);
            return 0;
        }

        ptr++;
        curNode = ptr;
        tree[cur].nxt[ch] = curNode;
        tree[curNode].length = tree[cur].length + 2;
        tree[curNode].startPos = pos - tree[curNode].length + 1;
        tree[curNode].endPos = pos;



        if(tree[curNode].length == 1) {
            tree[curNode].suffixLink = 2;
            printf("F1 CUR = %d\n",cur);
            //return 1;
        }
        else{
            while(true) {
                cur = tree[cur].suffixLink;
                printf("CUR = %d\n",cur);
                int curLength = tree[cur].length;
                printf("curLength = %d, POS-1-curLength = %d,  s[%d] = %c s[%d] = %c\n",curLength,pos-1-curLength,pos-1-curLength,s[pos-1-curLength],pos,s[pos]);
                if(pos-1-curLength >= 0 && s[pos-1-curLength] == s[pos]) {
                    tree[curNode].suffixLink = tree[cur].nxt[ch];
                    break;
                }
            }

            tree[curNode].suffixLink = tree[cur].nxt[ch];
            printf("F CUR = %d\n",cur);
        }

        printf("Number of Node: %d\n\n",curNode);
        for(int i=3; i<=curNode; i++){
            printf("tree[%d] = ",i);
            for(int j=tree[i].startPos; j<=tree[i].endPos; j++){
                printf("%c",s[j]);
            }
            printf(" length = %d  suffixLink = %d\n",tree[i].length, tree[i].suffixLink);
            printf("\n");
        }
        printf("\n");



        return 1;
    }

    void clear(){
        for(int i= 0;i <= ptr ;i ++) {
            memset(tree[i].nxt,0,sizeof(tree[i].nxt));
        }
    }
};
PalTree Pt;
int main()
{
    int t,cs=0;  scanf("%d",&t);
    while(t--) {
        scanf("%s",Pt.s);
        Pt.init();
        int ans = 0;
        for(int i= 0; Pt.s[i]; i ++) {
            ans += Pt.addLetter(i);
        }
        printf("Case #%d: %d\n",++cs, ans);
        Pt.clear();
    }
    return 0;
}
/*
10
abaabaaccabacec
abaaacaaddaeabaeabba

*/
