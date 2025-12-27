#include<bits/stdc++.h>
using namespace std;
char st[205][205],wr[205];
int mw[30],ms[30];
int R,C,W;
bool chk()
{
    for(int c=0; c<26; c++){
        if(ms[c]!=mw[c]){
            return false;
        }
    }
    return true;
}
bool horizontal()
{
    int sz=strlen(wr);

    if(sz>C){
        return false;
    }

    for(int i=0; i<R; i++)
    {
        memset(ms,0,sizeof(ms));

        for(int j=0; j<sz; j++){
            int ch=st[i][j]-'a';
            ms[ch]++;
        }

        if(chk()){
            return true;
        }

        for(int j=sz; j<C; j++)
        {
            int cp=st[i][j-sz]-'a';
            ms[cp]--;

            int ch=st[i][j]-'a';
            ms[ch]++;

            if(chk()){
                return true;
            }
        }
    }

    return false;
}
bool vertical()
{
    int sz=strlen(wr);

    if(sz>R){
        return false;
    }

    for(int j=0; j<C; j++)
    {
        memset(ms,0,sizeof(ms));

        for(int i=0; i<sz; i++){
            int ch=st[i][j]-'a';
            ms[ch]++;
        }

        if(chk()){
            return true;
        }

        for(int i=sz; i<R; i++)
        {
            int cp=st[i-sz][j]-'a';
            ms[cp]--;

            int ch=st[i][j]-'a';
            ms[ch]++;

            if(chk()){
                return true;
            }
        }
    }

    return false;
}
bool valid(int tx,int ty)
{
    if(tx>=0&&tx<R&&ty>=0&&ty<C) return true;
    return false;
}
bool diagonalUL()
{
    int sz=strlen(wr);

    if(sz>R||sz>C){
        return false;
    }

    for(int x=0; x<R; x++)
    {
        int i=x;
        if(i+sz>R){
            break;
        }

        memset(ms,0,sizeof(ms));

        for(int j=0; j<sz; j++,i++){
            if(valid(i,j)){
                int ch=st[i][j]-'a';
                ms[ch]++;
            }
        }

        if(chk()){
            return true;
        }

        for(int j=sz; j<C; j++,i++)
        {
            if(valid(i,j))
            {
                int cp=st[i-sz][j-sz]-'a';
                ms[cp]--;

                int ch=st[i][j]-'a';
                ms[ch]++;

                if(chk()){
                    return true;
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

        if(j+sz>C){
            break;
        }

        memset(ms,0,sizeof(ms));

        for(int i=0; i<sz; i++,j++){
            if(valid(i,j)){
                int ch=st[i][j]-'a';
                ms[ch]++;
            }
        }

        if(chk()){
            return true;
        }

        for(int i=sz; i<R; i++,j++)
        {
            if(valid(i,j))
            {
                int cp=st[i-sz][j-sz]-'a';
                ms[cp]--;

                int ch=st[i][j]-'a';
                ms[ch]++;

                if(chk()){
                    return true;
                }
            }
            else{
                break;
            }
        }
    }

    return false;
}
bool diagonalLL()
{
    int sz=strlen(wr);

    if(sz>R||sz>C){
        return false;
    }

    for(int y=0; y<C; y++)
    {
        int j=y;
        if(j+sz>C){
            break;
        }

        memset(ms,0,sizeof(ms));

        for(int i=R-1,k=0; k<sz; i--,j++,k++){
            if(valid(i,j)){
                int ch=st[i][j]-'a';
                ms[ch]++;
            }
        }

        if(chk()){
            return true;
        }

        for(int i=R-sz-1; i>=0; i--,j++)
        {
            if(valid(i,j))
            {
                int cp=st[i+sz][j-sz]-'a';
                ms[cp]--;

                int ch=st[i][j]-'a';
                ms[ch]++;

                if(chk()){
                    return true;
                }
            }
            else{
                break;
            }
        }
    }

    for(int x=R-2; x>=0; x--)
    {
        int i=x;

        if(i+1<sz){
            break;
        }

        memset(ms,0,sizeof(ms));

        for(int j=0; j<sz; j++,i--){
            if(valid(i,j)){
                int ch=st[i][j]-'a';
                ms[ch]++;
            }
        }

        if(chk()){
            return true;
        }

        for(int j=sz; j<C; j++,i--)
        {
            if(valid(i,j))
            {
                int cp=st[i+sz][j-sz]-'a';
                ms[cp]--;

                int ch=st[i][j]-'a';
                ms[ch]++;

                if(chk()){
                    return true;
                }
            }
            else{
                break;
            }
        }
    }

    return false;
}
int main()
{
    while(scanf("%d%d%d",&R,&C,&W)==3)
    {
        for(int i=0; i<R; i++)
        {
            scanf("%s",st[i]);
        }

        int ans=0;

        for(int i=0; i<W; i++)
        {
            scanf("%s",wr);
            int sz=strlen(wr);
            memset(mw,0,sizeof(mw));

            for(int j=0; j<sz; j++){
                mw[wr[j]-'a']++;
            }

            bool status=false;
            //cout << status << " horizontal \n";
            status=horizontal();
            if(status){
                //cout << "hor\n";
                ans++;
                continue;
            }
            //cout << status << " vertical \n";
            status=vertical();
            if(status){
                //cout << "ver\n";
                ans++;
                continue;
            }

            //cout << status << " diagonalUL \n";
            status=diagonalUL();
            if(status){
                //cout << "d1\n";
                ans++;
                continue;
            }

            //cout << status << " diagonalLL \n";

            status=diagonalLL();
            if(status){
                //cout << "d2\n";
                ans++;
                continue;
            }

            //cout << status << " diagonalLL \n";
        }

        printf("%d\n",ans);
    }

    return 0;
}


