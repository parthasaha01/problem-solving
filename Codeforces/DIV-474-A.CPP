#include<bits/stdc++.h>
using namespace std;
string s;
int fr[30];
int main()
{
    cin>>s;
    int n = s.size();

    memset(fr,0,sizeof(fr));

    for(int i=0; i<n; i++){
        fr[s[i]-'a']++;
    }

    if(n==1||n==2){
            printf("NO\n");
            return 0;
    }

    int cur = 0;
    int flag = 1;
    for(int i=0; i<n; i++){
        int id = s[i]-'a';
        if(id!=cur){
            cur++;
            if(id!=cur){
                flag=0;
                break;
            }
        }
    }

    if(flag==0){
        printf("NO\n");
        return 0;
    }

    if(fr[0]==0 || fr[1]==0 || fr[2]==0){
        printf("NO\n");
        return 0;
    }

    if(fr[2]==fr[0] || fr[2]==fr[1]){
        printf("YES\n");
        return 0;
    }
    else{
        printf("NO\n");
        return 0;
    }

    return 0;
}
