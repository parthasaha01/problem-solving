/* You are given a string S. We want to know how many distinct substring of S which is palindrome.*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005; /// Maximum Length of the String
struct Node{
    int nxt[26]; /// stores insertion Node for all characters a-z.
    int length; /// length -> stores length of substring
    int suffixLink; /// suffixLink -> stores the Maximum Palindromic Suffix Node for the current Node
    int startPos, endPos; /// store start and end indexes of current Node inclusively
};
struct PalTree{
    Node tree[MAXN]; /// Node for each pallindrome
    Node root1, root2;
    /* root1 -> is a pallindrome of -1 length to accept odd length pallindrome (“a”,“c”,“d” is
       accepted by this node, in other words single character pallindrome are accepted by this node)
       root2 -> is a pallindrome of 0 length to accept even length pallindrome
       (“aa”, “bb”,”abba” is accepted by this node) */

    char s[MAXN];   // String
    int curNode,ptr;

    void init() {	/// Initialize pallindromic tree
        root1.length= -1, root1.suffixLink = 1;
        root2.length = 0, root2.suffixLink = 1;
        tree[1] = root1, tree[2] = root2;
        curNode = ptr = 2;
    }

    /// If addition of s[pos] form a new pallindrome different from the previously present,
    /// return 1. Otherwise return 0.
    bool addLetter(int pos) {
        int ch = s[pos]-'a';
        int cur = curNode;

        /*  search for Node X such that s[pos] X s[pos] is maximum palindrome ending at position pos.
            iterate down the suffix link of currNode to find X and X is also Palindrome  */

        while(true) {
            int curLength = tree[cur].length;
            if(pos-1-curLength >= 0 && s[pos-1-curLength] == s[pos]) break;
            cur = tree[cur].suffixLink;
        }

        /// Now we have found X. X = string at Node cur
        ///  Check : if s[pos] X s[pos] already exists or not
        if(tree[cur].nxt[ch] != 0){
            /// Previously occurred Pallindrome, s[pos] X s[pos] already exists in the tree
            /// Here may need some computation
            curNode = tree[cur].nxt[ch];
            return 0;
        }

        ptr++;   /// creating new node. i.e. Adding New Pallindrome
        curNode = ptr;	/// making new Node as current Node
        tree[cur].nxt[ch] = curNode;    /// making new Node as child of X with weight as s[pos]
        tree[curNode].length = tree[cur].length + 2;      /// calculating length of new Node
        tree[curNode].startPos = pos - tree[curNode].length + 1; /// store start index of current Node
        tree[curNode].endPos = pos;	   /// store end index of current Node

        /*  Setting the suffix edge for the newly created Node tree[ptr]. Finding some String Y
        such that s[pos] + Y + s[pos] is longest possible palindromic suffix for newly created Node.*/

        if(tree[curNode].length == 1) {
            /// new palindrome's length is 1.
            tree[curNode].suffixLink = 2; /// making its suffix link to be the null string
            return 1;
        }

        while(true) {
            cur = tree[cur].suffixLink;
            int curLength = tree[cur].length;
            if(pos-1-curLength >= 0 && s[pos-1-curLength] == s[pos]) {
                tree[curNode].suffixLink = tree[cur].nxt[ch];
                break;
            }
        }

        /// Now we have found string Y. linking current Nodes suffix link with s[pos]+Y+s[pos]
        /// May need some computation
        tree[curNode].suffixLink = tree[cur].nxt[ch];

        return 1;
    }

    /// Clears Tree . Needed for multiple testcases
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
