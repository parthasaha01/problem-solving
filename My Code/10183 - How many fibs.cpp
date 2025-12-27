#include<bits/stdc++.h>
using namespace std;
string ss[505];
void precalculate()
{
    ss[0] = "0";
    ss[1] = "1";
    ss[2] = "2";

    for(int i=3; i<=500; i++)
    {
        string x,y,z;
        x = ss[i-1];
        y = ss[i-2];

        reverse(x.begin(),x.end());
        reverse(y.begin(),y.end());

        int a,b,s,ci=0,k;
        for(k=0; k<y.size(); k++)
        {
            a = x[k]-'0';
            b = y[k]-'0';
            s = a+b+ci;
            ci = s/10;
            s = s%10;
            z += s+'0';
        }

        for( ; k<x.size(); k++)
        {
            a = x[k]-'0';
            s = a+ci;
            ci = s/10;
            s = s%10;
            z += s+'0';
        }

        if(ci>0)z += ci+'0';

        reverse(z.begin(),z.end());

        ss[i] = z;
    }
}
int check(string x,string y)
{
    if(x.size()==y.size())
    {
        if(x==y) return 1;
        if(x>y) return 2;
        if(x<y) return 3;
    }

    if(x.size()>y.size())return 2;
    if(x.size()<y.size())return 3;
}
int Upper(string x)
{
    if(x=="0")return 1;
    int lo=1;
    int hi=500;
    int id=0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        int flag = check(ss[md],x);
        if(flag==1){
            id=md;
            break;
        }
        else if(flag==2){
            hi=md-1;
            id=md;
        }
        else{
            lo=md+1;
        }
    }
    return id;
}
int Lower(string x)
{
    if(x=="0")return 0;
    int lo=1;
    int hi=500;
    int id=0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        int flag=check(ss[md],x);

        if(flag==1){
            //cout << ss[md] << " == " << x << endl;
            id=md;
            break;
        }
        else if(flag==2){
            //cout << ss[md] << " > " << x << endl;
            hi=md-1;
        }
        else{
            //cout << ss[md] << " < " << x << endl;
            lo=md+1;
            id=md;
        }
    }
    return id;
}
int main()
{
    precalculate();


    char p[105],q[105];
    while(scanf("%s %s",&p,&q))
    {
        string a,b;

        for(int i=0; i<strlen(p); i++)a+=p[i];
        for(int i=0; i<strlen(q); i++)b+=q[i];

        if(a=="0"&&b=="0")break;

        int flag = check(a,b);
        if(flag==2)swap(a,b);

        int lw = Upper(a);
        int rg = Lower(b);

        //printf("lw=%d rg=%d\n",lw,rg);

        printf("%d\n",rg-lw+1);
    }
    return 0;
}

