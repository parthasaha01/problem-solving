#include<bits/stdc++.h>
using namespace std;

char ch[15][10];
int main()
{
    ch[0][1] = ' ';
    ch[0][2] = '0';
    ch[0][3] = ' ';
    ch[0][4] = '0';

    ch[1][1] = '.';
    ch[1][2] = ',';
    ch[1][3] = '?';
    ch[1][4] = '"';

    ch[2][1] = 'a';
    ch[2][2] = 'b';
    ch[2][3] = 'c';
    ch[2][4] = '2';

    ch[3][1] = 'd';
    ch[3][2] = 'e';
    ch[3][3] = 'f';
    ch[3][4] = '3';

    ch[4][1] = 'g';
    ch[4][2] = 'h';
    ch[4][3] = 'i';
    ch[4][4] = '4';

    ch[5][1] = 'j';
    ch[5][2] = 'k';
    ch[5][3] = 'l';
    ch[5][4] = '5';

    ch[6][1] = 'm';
    ch[6][2] = 'n';
    ch[6][3] = 'o';
    ch[6][4] = '6';

    ch[7][1] = 'p';
    ch[7][2] = 'q';
    ch[7][3] = 'r';
    ch[7][4] = 's';

    ch[8][1] = 't';
    ch[8][2] = 'u';
    ch[8][3] = 'v';
    ch[8][4] = '8';

    ch[9][1] = 'w';
    ch[9][2] = 'x';
    ch[9][3] = 'y';
    ch[9][4] = 'z';

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[105];
        for(int i=0; i<n; i++) cin>>a[i];
        int p[105];
        for(int i=0; i<n; i++) cin>>p[i];

        string s;
        for(int i=0; i<n; i++)
        {
            s += ch[a[i]][p[i]];
        }

        cout<<s<<endl;
    }

    return 0;
}

