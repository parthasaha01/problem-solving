#include<bits/stdc++.h>
using namespace std;
string st[150],wr[150];
map<char, int>mw,mt,temp;
map<map<char, int>, int>mp;
int R,C,W;
void horizontal()
{
    for(int i=0; i<R; i++)
    {
        mt.clear();
        for(int j=0; j<C; j++)
        {
            char ch=st[i][j];

            mt[ch]++;
            temp.clear();
            for(char c='a'; c<='z'; c++){
                temp[c]=mt[c];
            }

            for(int k=0; k<=j; k++)
            {
                if(mp[mt]==0){
                    mp[mt]=1;
                }
                char ck=st[i][k];
                mt[ck]--;
            }

            mt.clear();
            for(char c='a'; c<='z'; c++){
                mt[c]=temp[c];
            }
        }
    }

}
void vertical()
{
    for(int j=0; j<C; j++)
    {
        mt.clear();
        for(int i=0; i<R; i++)
        {
            char ch=st[i][j];

            mt[ch]++;
            temp.clear();
            for(char c='a'; c<='z'; c++){
                temp[c]=mt[c];
            }

            for(int k=0; k<=i; k++)
            {
                if(mp[mt]==0){
                    mp[mt]=1;
                }
                char ck=st[k][j];
                mt[ck]--;
            }

            mt.clear();
            for(char c='a'; c<='z'; c++){
                mt[c]=temp[c];
            }
        }
    }
}
bool valid(int tx,int ty)
{
    if(tx>=0&&tx<R&&ty>=0&&ty<C) return true;
    return false;
}
void diagonalUL()
{
    for(int x=0; x<R; x++)
    {
        int i=x;
        mt.clear();
        for(int j=0; j<C; j++,i++)
        {
            if(valid(i,j))
            {
                char ch=st[i][j];
                mt[ch]++;
                temp.clear();
                for(char c='a'; c<='z'; c++){
                    temp[c]=mt[c];
                }

                for(int u=x,v=0; u<=i&&v<=j; u++,v++)
                {
                    if(mp[mt]==0){
                        mp[mt]=1;
                    }
                    char ck=st[u][v];
                    mt[ck]--;
                }
                mt.clear();
                for(char c='a'; c<='z'; c++){
                    mt[c]=temp[c];
                }
            }
            else{
                break;
            }
        }
    }

    for(int y=1; y<C; y++)
    {
        int j=y;
        mt.clear();
        for(int i=0; i<R; i++,j++)
        {
            if(valid(i,j))
            {
                char ch=st[i][j];
                mt[ch]++;
                temp.clear();
                for(char c='a'; c<='z'; c++){
                    temp[c]=mt[c];
                }

                for(int u=0,v=y; u<=i&&v<=j; u++,v++)
                {
                    if(mp[mt]==0){
                        mp[mt]=1;
                    }
                    char ck=st[u][v];
                    mt[ck]--;
                }
                mt.clear();
                for(char c='a'; c<='z'; c++){
                    mt[c]=temp[c];
                }
            }
            else{
                break;
            }
        }
    }
}
void diagonalLL()
{
    for(int x=R-1; x>=0; x--)
    {
        int i=x;
        mt.clear();
        for(int j=0; j<C; j++,i--)
        {
            if(valid(i,j))
            {
                char ch=st[i][j];
                mt[ch]++;
                temp.clear();
                for(char c='a'; c<='z'; c++){
                    temp[c]=mt[c];
                }

                for(int u=x,v=0; u>=i&&v<=j; u--,v++)
                {
                    if(mp[mt]==0){
                        mp[mt]=1;
                    }
                    char ck=st[u][v];
                    mt[ck]--;
                }
                mt.clear();
                for(char c='a'; c<='z'; c++){
                    mt[c]=temp[c];
                }
            }
            else{
                break;
            }
        }
    }

    for(int y=1; y<C; y++)
    {
        int j=y;
        mt.clear();
        for(int i=R-1; i>=0; i--,j++)
        {
            if(valid(i,j))
            {
                char ch=st[i][j];
                mt[ch]++;
                temp.clear();
                for(char c='a'; c<='z'; c++){
                    temp[c]=mt[c];
                }

                for(int u=R-1,v=y; u>=i&&v<=j; u--,v++)
                {
                    if(mp[mt]==0){
                        mp[mt]=1;
                    }
                    char ck=st[u][v];
                    mt[ck]--;
                }
                mt.clear();
                for(char c='a'; c<='z'; c++){
                    mt[c]=temp[c];
                }
            }
            else{
                break;
            }
        }
    }
}
int main()
{
    while(cin>>R>>C>>W)
    {
        mp.clear();

        for(int i=0; i<R; i++)
        {
            cin>>st[i];
        }

        horizontal();
        vertical();
        diagonalUL();
        diagonalLL();

        for(int i=0; i<W; i++)
        {
            cin>>wr[i];
        }

        int ans=0;

        for(int i=0; i<W; i++)
        {
            int sz=wr[i].size();
            mw.clear();
            for(int j=0; j<sz; j++)
            {
                char c=wr[i][j];
                mw[c]++;
            }

            for(char c='a'; c<='z'; c++){
                mw[c]=mw[c];
            }

            if(mp[mw]!=0){
                ans++;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
/*
5 6 3
asdfrd
sderfg
fdggtg
aaerds
fsrfgy
gdtg
drea
fsrrf

3 3 3
abc
def
dfr
abc
efd
zsd

3 3 3
abc
def
dfr
frc
efd
dda

3 3 3
abc
def
dfr
ear
bfr
dda

*/

