#include<bits/stdc++.h>
using namespace std;
char s[105],ss[105],ts[105],tss[105];
//string s,ss,ts,tss;
int vis1[150],vis2[150];
int main()
{
    int t;
    scanf("%d",&t);
    getchar();

    for(int kase=1; kase<=t; kase++)
    {
        gets(ts);
        gets(tss);

        int sz1=strlen(ts);
        int k=0;
        for(int i=0; i<sz1; i++){
            if(ts[i]!=' '){
                if(ts[i]>='A'&&ts[i]<='Z'){
                    s[k++]=ts[i]+32;
                }
                else{
                    s[k++]=ts[i];
                }
            }
        }
        s[k]='\0';

        int sz2=strlen(tss);
        k=0;
        for(int i=0; i<sz2; i++){
            if(tss[i]!=' '){
                if(tss[i]>='A'&&tss[i]<='Z'){
                    ss[k++]=tss[i]+32;
                }
                else{
                    ss[k++]=tss[i];
                }
            }
        }
        ss[k]='\0';

        sz1=strlen(s);
        sz2=strlen(ss);

        //sort(s,s+sz1);
        //sort(ss,ss+sz2);

        memset(vis1,0,sizeof(vis1));
        memset(vis2,false,sizeof(vis2));

        for(int i=0; i<sz1; i++){
            vis1[s[i]]++;
        }
        for(int i=0; i<sz2; i++){
            vis2[ss[i]]++;
        }

        bool flag=true;

        if(sz1<=sz2)
        {
            for(int i=0; i<sz1; i++){
                if(vis1[s[i]]>vis2[s[i]]){
                    flag=false;
                    break;
                }
            }
        }
        else
        {
            for(int i=0; i<sz2; i++){
                if(vis2[ss[i]]>vis1[ss[i]]){
                    flag=false;
                    break;
                }
            }
        }

        if(flag==true){
            printf("Case %d: Yes\n",kase);
        }
        else{
            printf("Case %d: No\n",kase);
        }

    }

    return 0;
}
