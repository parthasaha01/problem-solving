/*
* Allah is Almighty.......
*
* Mehedi Hasan Angkur <thisisangkur@gmail.com>
* CSE 11th Batch,MBSTU
* uva,cf id mbstu_angkur..
*
* keep coding...
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define D double
#define pb push_back
#define mpp make_pair
#define sf scanf
#define pf printf
#define ff first
#define ss second
#define sz 200000
#define sq(x) x*x
#define eps 1e-8
#define PI (2*acos(0.0))
#define mem(a, b) memset(a, b, sizeof a)
#define dist(x1, y1, x2, y2) sqrt(sq(x1-x2)+sq(y1-y2))
#define FastIO ios_base::sync_with_stdio(0)
const int inf = 0x7f7f7f7f;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct node
{

    int leftpos, rightpos;
    int nL, nR;
    node()
    {
        nL = 0;
        nR = 0;
        leftpos=-1;
        rightpos=-1;
    }
};

int lol=0;

int query(int val, int cmp, int index, int depth, node* tree)
{
    int ans=0;
    for(int i=depth-1; i>=0; --i)
    {
        int vBit = val>>i & 1;
        int cBit = cmp>>i & 1;
        if(cBit)
        {
            if(vBit)
            {
                ans += tree[index].nR;
                index = tree[index].leftpos;
            }
            else
            {
                ans += tree[index].nL;
                index = tree[index].rightpos;
            }
        }
        else
        {
            if(vBit)
                index = tree[index].rightpos;
            else
                index = tree[index].leftpos;
        }
        if(index==-1)
            break;
    }
    return ans;
}

void insert(int val, int index, int depth, node *tree)
{
    for(int i = depth-1; i>=0; --i)
    {
        int bit = val>>i & 1;
        if(bit)
        {
            tree[index].nR++;
            if(tree[index].rightpos==-1)
            {
                tree[index].rightpos = ++lol;
                index = lol;
            }
            else
                index = tree[index].rightpos;
        }
        else
        {
            tree[index].nL++;
            if(tree[index].leftpos==-1)
            {
                tree[index].leftpos = ++lol;
                index = lol;
            }
            else
                index = tree[index].leftpos;
        }
    }
}

int main()
{
    int d;
    sf("%d", &d);
    while(d--)
    {

        lol=0;
        node tree[sz];
        int n, k;
        sf(" %d %d", &n, &k);
        int sum = 0, t=0;
        long long ans=0;
        insert(0, 0, 18, tree);
        while(n--)
        {
            scanf(" %d", &t);
            sum = sum ^ t;
            ans += query(sum, k, 0, 18, tree);
            insert(sum, 0, 18, tree);
        }
        printf("%lld\n", ans);
    }
}
