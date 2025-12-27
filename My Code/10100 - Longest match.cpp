#include<bits/stdc++.h>
using namespace std;
string s1,s2;
map<string,int>mp;
map<int,string>sp;
int k,la,lb,a[1005],b[1005],dp[1005][1005];
int lcs(int i, int j)
{
    if(i>la)return 0;
    if(j>lb)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int ret,ret1,ret2;
    if(a[i]==b[j]){
        ret = 1+lcs(i+1,j+1);
    }
    else{
        ret1 = lcs(i+1,j);
        ret2 = lcs(i,j+1);
        ret = max(ret1,ret2);
    }
    return dp[i][j] = ret;
}
int main()
{
    int ks=0;
    while(getline(cin,s1))
    {
        getline(cin,s2);

        if(s1=="" || s2==""){
            printf("%2d. Blank!\n",++ks);
            continue;
        }

        for(int i=0; i<s1.size(); i++){
            if((s1[i]>='A'&&s1[i]<='Z')||(s1[i]>='a'&&s1[i]<='z')||(s1[i]>='0'&&s1[i]<='9')){
                //if(s1[i]>='A'&&s1[i]<='Z')s1[i]=s1[i]+32;
            }
            else{
                s1[i]=' ';
            }
        }

        for(int i=0; i<s2.size(); i++){
            if((s2[i]>='A'&&s2[i]<='Z')||(s2[i]>='a'&&s2[i]<='z')||(s2[i]>='0'&&s2[i]<='9')){
                //if(s2[i]>='A'&&s2[i]<='Z')s2[i]=s2[i]+32;
            }
            else{
                s2[i]=' ';
            }
        }

        string s; s="";
        k=0; la=0;
        mp.clear(); sp.clear();

        for(int i=0; i<s1.size(); i++){
            if(s1[i]==' '){
                if(s.size()!=0){
                    if(mp[s]==0) mp[s] = ++k;
                    a[++la] = mp[s];
                    sp[mp[s]]=s;
                }
                s="";
            }
            else{
                s+=s1[i];
            }
        }
        if(s.size()!=0){
            if(mp[s]==0) mp[s] = ++k;
            a[++la] = mp[s];
            sp[mp[s]]=s;
        }

        s="";
        lb=0;
        for(int i=0; i<s2.size(); i++){
            if(s2[i]==' '){
                if(s.size()!=0){
                    if(mp[s]==0) mp[s] = ++k;
                    b[++lb] = mp[s];
                    sp[mp[s]]=s;
                }
                s="";
            }
            else{
                s+=s2[i];
            }
        }
        if(s.size()!=0){
            if(mp[s]==0) mp[s] = ++k;
            b[++lb] = mp[s];
            sp[mp[s]]=s;
        }
        s="";

//        printf("la=%d lb=%d\n",la,lb);
//
//        for(int i=1; i<=la; i++){
//            printf("%d ",a[i]);
//        }
//        printf("\n");
//
//        for(int i=1; i<=lb; i++){
//            printf("%d ",b[i]);
//        }
//        printf("\n");

        //for(int i=1; i<=)

        memset(dp,-1,sizeof(dp));
        int ans = lcs(1,1);

        printf("%2d. Length of longest match: %d\n",++ks,ans);
    }
    return 0;
}
