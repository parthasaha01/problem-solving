#include<bits/stdc++.h>
using namespace std;
int fr[1500];
int main()
{
    string s;
    getline(cin,s);

    for(int i=0; i<s.size(); i++){
        if(s[i]==' ')continue;
        if(s[i]>='a'&& s[i]<='z')fr[s[i]-'a']++;
        if(s[i]>='A'&& s[i]<='Z')fr[s[i]-'A']++;
    }

    int flag = 1;
    for(int i=0; i<26; i++){
        if(fr[i]<1){
            flag = 0;
            break;
        }
    }

    if(flag){
        printf("pangram\n");
    }
    else{
        printf("not pangram\n");
    }

    return 0;
}
