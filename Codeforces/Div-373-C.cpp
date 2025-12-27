#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100005
string ss;
int main()
{
    int n,t;
    char s[200005];
    while(scanf("%d%d",&n,&t)==2)
    {
        getchar();
        gets(s);
        ss=s;

        int p=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='.')
            {
                p=i+1;
                break;
            }
        }

        int sz=strlen(s);
        bool change=false;
        int x;

        for(int i=p; i<sz; i++)
        {
            if(s[i]>='5'){
                s[i]='\0';
                x=i-1;
                change=true;
                break;
            }
        }

        bool flag=false;
        bool four=false;

        if(change)
        {
            int cnt=t-1;
            int i=x;
            while(s[i]=='4')
            {
                if(cnt==0){
                    four=true;
                    s[i]+=1;
                    s[i+1]='\0';
                    break;
                }

                s[i]='\0';
                i--;
                cnt--;
            }

            if(s[i]=='.')
            {
                s[i+1]='\0';
                bool nine=true;
                for(int r=i-1; r>=0; r--)
                {
                    if(s[r]=='9')
                    {
                        s[r]='0';
                    }
                    else
                    {
                        s[r]+=1;
                        nine=false;
                        break;
                    }
                }

                if(nine)
                {
                    flag=true;
                }
            }
            else
            {
                if(!four)
                {
                    s[i]+=1;
                }
            }
        }

        sz=strlen(s);
        for(int i=sz-1; i>=0; i--){
            if(s[i]!='0'){
                if(s[i]=='.'){
                    s[i]='\0';
                }
                else{
                    s[i+1]='\0';
                }
                break;
            }
        }

        if(flag)
        {
            printf("1");
            puts(s);
        }
        else{
            puts(s);
        }
    }

    return 0;
}
/*
10 20
999.123415
10 20
899.123415
10 20
999.125415
10 20
999.44446

*/
