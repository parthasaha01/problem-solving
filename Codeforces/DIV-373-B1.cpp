#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100005
string s;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        cin>>s;

        int pb=0,pr=0;
        for(int i=0; i<n; i+=2){
            if(s[i]=='r'){
                pb++;
            }
        }
        for(int i=1; i<n; i+=2){
            if(s[i]=='b'){
                pr++;
            }

        }

        int diff=abs(pb-pr);
        int minn1=diff+min(pb,pr);


        int pb2=0,pr2=0;
        for(int i=0; i<n; i+=2){
            if(s[i]=='b'){
                pr2++;
            }
        }
        for(int i=1; i<n; i+=2){
            if(s[i]=='r'){
                pb2++;
            }

        }

        int diff2=abs(pb2-pr2);
        int minn2=diff2+min(pb2,pr2);

        int ans=min(minn1,minn2);

        printf("%d\n",ans);
    }

    return 0;
}

