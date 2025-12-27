#include<bits/stdc++.h>
using namespace std;
string s;
int fre[30];
int main()
{
    while(cin>>s)
    {
        memset(fre,-1,sizeof(fre));
        int p1,p2;
        char ch;
        for(int i=0; i<s.size(); i++)
        {
            int c=s[i]-'A';
            if(fre[c]==-1)
            {
                fre[c]=i;
            }
            else
            {
                p1=fre[c];
                p2=i;
                ch=s[i];
            }
        }

        int d=p2-p1;

        if(d==1)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            if(d%2==0)
            {
                int m=d/2;
                int n=13-m;
                ss[n-1]=ch;
                int k=p1-1;
                int p=0;
                for(int i=n-2; i>=0&&k>=0; i--,k--){
                    ss[i]=s[k];
                    p=i;
                }
                for(int i=13; i<26; i++){

                }
            }
        }
    }
    return 0;
}
