#include<bits/stdc++.h>
using namespace std;
int n,cnt,flag;
string s;
void fun(int pos,int pr)
{
    if(flag==1)return;
    if(pos==n){
        //vv.insert(ss);
//        if(vv.size()==2){
//            flag = 1;
//        }
        cnt++;
        if(cnt==2){
            flag = 1;
        }
        return;
    }

    if(s[pos]=='0'){
        for(int i=1; i<=3; i++)
        {
            if(pr==i)continue;
            fun(pos+1,i);
        }
    }
    else{
        if(pr==(s[pos]-'0'))return;
        else fun(pos+1,s[pos]-'0');
    }
}
int main()
{
   // int n;
    cin>>n;
    //string s;
    cin>>s;

    for(int i=0; i<n; i++)
    {
        if(s[i]=='C')s[i]='1';
        else if(s[i]=='M')s[i]='2';
        else if(s[i]=='Y')s[i]='3';
        else s[i]='0';
    }

    flag = 0;
    cnt = 0;

    fun(0,-1);

    if(flag)printf("Yes\n");
    else printf("No\n");

    //main();

    return 0;

}
