#include<bits/stdc++.h>
using namespace std;
int n,fr[10];;
string a,x;
int main()
{
    cin>>n>>a;

    for(int i=0; i<n; i++){
        int d = a[i]-'0';
        if(d==0)continue;
        if(d==1)continue;
        if(d==2)fr[2]+=1;
        if(d==3)fr[3]+=1,fr[2]+=1;
        if(d==4)fr[3]+=1,fr[2]+=3;
        if(d==5)fr[5]+=1,fr[3]+=1,fr[2]+=3;
        if(d==6)fr[5]+=1,fr[3]+=2,fr[2]+=4;
        if(d==7)fr[7]+=1,fr[5]+=1,fr[3]+=2,fr[2]+=4;
        if(d==8)fr[7]+=1,fr[5]+=1,fr[3]+=2,fr[2]+=7;
        if(d==9)fr[7]+=1,fr[5]+=1,fr[3]+=4,fr[2]+=7;
    }

    for(int i=7; i>1; i--){
        if(fr[i]==0)continue;
        for(int k=1; k<=fr[i]; k++)x+=i+'0';
        if(i==7)fr[5]-=1*fr[i], fr[3]-=2*fr[i], fr[2]-=4*fr[i];
        if(i==5)fr[3]-=1*fr[i], fr[2]-=3*fr[i];
        if(i==3)fr[2]-=1*fr[i];
    }

    cout<<x<<endl;

    return 0;
}
